/*
    Description:
        This program is a simple console-based ordering system for a restaurant.
        It allows the user to select items from a pre-defined menu, calculates the
        total cost of their order, and prints out a receipt. The program prompts
        the user to enter their name, address, and phone number at the beginning.
        If the delivery address is not in "Mansoura", there is a delivery fee of
        $5. If the user orders more than five items, there is a 20% discount on
        the total order price.

    Pseudocode:
        1) Define the structures for customer and product.
        2) Create an array of products with their names and prices
        3) Ask the customer to input their name, address, and phone number using the customer_info() function
        4) Check if the customer's address is "Mansoura" or not, and add delivery fees accordingly
        5) Display the menu to the customer
        6) Ask the customer to enter the number of the item they want to order, then add the item's price to the total
        7) Ask the customer if they want to continue ordering or pay
        8) If the customer wants to continue ordering, repeat step 6
        9) If the customer wants to start a new order, reset the total to 0 and repeat step 5
       10) If the customer has ordered more than 5 items, apply a discount of 20%
       11) Print out the customer's receipt

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 40
#define MAX_ORDERS 20
#define NUM_MENU_ITEMS 10

void customer_info();
void print_menu();

//---------------Step 1---------------//
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int phone_number;
} customer;

//---------------Step 2---------------//
typedef struct
{
    char product_name[MAX_NAME_LENGTH];
    int price;
    int repeated;
} product;

customer customer_1;

product menu[NUM_MENU_ITEMS] = {
    {"    Omlete sandwish   ", 10, 0},
    {"  Mix cheese Sandwich ", 12, 0},
    {"    Turkey Sandwich   ", 20, 0},
    {"Cheese burger sandwich", 30, 0},
    {"4 pieces Fried chicken", 50, 0},
    {"8 pieces Fried chicken", 80, 0},
    {"       5 nuggets      ", 30, 0},
    {"       Kids meal      ", 34, 0},
    {"      French Fries    ",  5, 0},
    {"       Soft drink     ", 10, 0},
};

void main()
{

    int total = 0, choice, counter = 0, delivery = 2,order=0;

    //---------------Step 3---------------//

    printf("\n\n****WELCOME TO OUR RESTAURANT**** \n\n");

    customer_info();
    //---------------Step 4---------------//
    if (strcmp(customer_1.address, "mansoura") != 0 && strcmp(customer_1.address, "Mansoura") != 0)
    {
        delivery = 5;
        printf("****There will be 5$ For Delivery**** \n");
    }

    //---------------Step 5---------------//
    print_menu();
    //--------------Step 6:10--------------//
    while (1)
    {
        printf("Enter number of meal you want,(0) to finish the order,(-1)to reset the order: ");
        scanf("%d", &choice);
        if (choice == -1)
        {
            total = 0;
            counter = 0;
            for (int i = 0; i < NUM_MENU_ITEMS; i++)
            {
                menu[i].repeated = 0;     //Reseting the counter of each product
            }
            print_menu();
            continue;
        }
        else if (choice == 0)
            break;

        total += menu[choice - 1].price;  //Calculating the total sum 
        menu[choice - 1].repeated++;      //Updating the counter of a specific product
        counter++;                        //Updating the no_of_orders

        printf("Total price will be: %d\n\n", total);
    }
    if (counter > 5)
    {
        total = total * 0.8;
    }

    //---------------Step 11---------------//

    printf("---------------Receipt---------------\n");
    printf("Order by :  %s\n", customer_1.name);
    printf("Address: %s\n", customer_1.address);
    printf("Phone no. :0%d\n\n", customer_1.phone_number);
printf("            Item        Amount    Price    T.price \n");
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
        if (menu[i].repeated > 0)
        {
            printf("%d-)%s x%d ----> %d$ ----> %d$\n",order+1, menu[i].product_name, menu[i].repeated, menu[i].price, menu[i].repeated*menu[i].price);
        order++;
        }
    }
    printf("\n");

    if (counter > 5)
    {
        printf("****YOU HAVE A 20\% DISCOUNT****\n");
    }

    printf("Total order price--> %d$ \n", total);
    printf("Delivery fees--> %d$\n", delivery);
    printf("Total price will be--> %d$\n\n", total + delivery);
    printf("-----------Have a nice day-----------\n");
}

//--------------Functions--------------//
void customer_info()
{
    printf("Enter your Name: ");
    gets(customer_1.name);
    printf("Enter your Address: ");
    gets(customer_1.address);
    printf("Enter your Phone Number: ");
    scanf("%d", &customer_1.phone_number);
    printf("\n");
}
void print_menu()
{
    for (int i = 0; i < NUM_MENU_ITEMS; i++)
    {
        printf("%d--> %s-->%d$\n", i + 1, menu[i].product_name, menu[i].price);
    }
    printf("\n");
}