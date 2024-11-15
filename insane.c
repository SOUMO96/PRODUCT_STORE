#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define MAX_ITEM_SIZE 100
#include <time.h>
#include <stdlib.h>

struct product
{
    char product[MAX_SIZE];
    int price;
    int quantity;
    int id;
};

int generate_random()
{
    srand(time(0));
    int num = (rand() % 1000) + 1;
    return num;
}
void enter_product(struct product products[], int *count);
void get_product(struct product products[], int count);

int main()
{

    struct product products[MAX_ITEM_SIZE];
    int count = 0;
    int choice;
    while (1)
    {
        printf("\n WELCOME\n");
        printf("\n 1) For Listing a New Product\n");
        printf(" 2) Get Information By Device Id\n ");
        printf("3) Exit!\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enter_product(products, &count);
            break;
        case 2:
            get_product(products, count);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid Input");
        }
    }
    return 0;
}
void enter_product(struct product products[], int *count)
{
    if (*count >= MAX_ITEM_SIZE)
    {
        printf("Size Not Supported!");
    }
    printf("ENTER THE NAME OF THE PRODUCT :");
    getchar();
    fgets(products[*count].product, MAX_ITEM_SIZE, stdin);
    products[*count].product[strcspn(products[*count].product, "\n")] = 0;

    printf("ENTER THE PRICE OF THE PRODUCT :");
    scanf("%d", &products[*count].price);

    printf("ENTER THE QUANTITY YOU WANT TO STORE :");
    scanf("%d",&products[*count].quantity);

    products[*count].id = *count + 1;

    printf("ID: %d\n", products[*count].id);
    (*count)++;
    
}
void get_product(struct product products[], int count)
{
    int search_id;
    int found = 0;
    printf("ENTER THE ID :");
    scanf("%d", &search_id);
    for (int i = 0; i < count; i++)
    {
        if (products[i].id == search_id)
        {
            printf("\nProduct found!\n");
            printf("CATAGORY: %s\n", products[i].product);
            printf("PRICE PER UNIT: %d\n", products[i].price);
            printf("AVALABLE QUANTITY: %d\n", products[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("INVALID ID!");
    }
}