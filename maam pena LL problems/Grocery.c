#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct ProductDetails{
    char prodID[9];
    char prodName[32];
    char shelf[5];
}ProductDetails;

typedef struct Product{
    ProductDetails details;
    float price;
    int stocks;
    int itemsSold;
}Product;

void clear()
{
    puts("PRESS ANY KEY TO CONTINUE...");
    getch();
    system("CLS");
}

void displayProduct(Product prod)
{
    char buffer[300];
    sprintf(buffer, "ID: %s\nName: %s\nPrice: %.2f\nShelf: %s\nStocks: %d\nItems Sold: %d\n\n", 
    prod.details.prodID, prod.details.prodName, prod.price, prod.details.shelf, 
    prod.stocks, prod.itemsSold);
    puts(buffer);
}
/*This function receives an array of products and a specific shelf. 
The function goes through the entire array of products and returns to the 
calling function all the Products that can be found on that shelf. 
Let the last Product have a stock of -1, to act as a sentinel value. */
Product* getAllShelfItems(Product P[], int count, char shelf[])
{
    int i, j;
    Product temp[count];
    Product* shelfProds;
    
    for(i = j = 0; i < count; i++){
        if(strcmp(P[i].details.shelf, shelf) == 0){
            temp[j] = P[i];
            j++;
        }
    }
    
    shelfProds = malloc(sizeof(Product) * (j+1));
    if(shelfProds != NULL){
        shelfProds[0].stocks = j;
        memcpy(shelfProds + 1, temp, sizeof(Product) * j);
    }
    
    return shelfProds;
}



/* This function receives an array of products and an int threshold. The function goes through the entire array of products and returns to the calling function all the Products that have stocks equal to or below the threshold. Let the last Product have a stock of -1, to act as a sentinel value.*/
Product* getLowStockItems(Product P[], int count, int threshold)
{
    int i, j;
    Product temp[count];
    Product* lowStocks;
    
    for(i = j = 0; i < count; i++){
        if(P[i].stocks <= threshold){
            temp[j] = P[i];
            j++;
        }
    }
    
    lowStocks = malloc(sizeof(Product) * (j+1));
    if(lowStocks != NULL){
        lowStocks[0].stocks = j;
        memcpy(lowStocks + 1, temp, sizeof(Product) * j);
    }
    
    return lowStocks;
}

/* This function receives an array of products an a specific id. The function goes through the entire array of products and checks if there is a product in the list with the same id as the parameter passed. If there is, return the index of that product. Else, return 0 */
int findProd(Product P[], int count, char id[])
{
    int i;
    
    for(i = 0; i < count && strcmp(P[i].details.prodID, id) != 0; i++){}
    return (i < count) ? i : -1;
}

/* This function receives an array of products, a sales threshold, and a multiplier. 
The function goes through the entire array of products, and updates the prices of ALL products 
who’s sales go BEYOND the sales threshold. New price is calculated as follows: price * multiplier. */
void updatePrices(Product P[], int count, int salesThresh, float multiplier)
{
    int i;
    
    for(i = 0; i < count; i++){
        if(P[i].itemsSold > salesThresh){
            P[i].price *= multiplier;
        }
    }
}

void displayProducts(Product P[], int size)
{
    int i;
    
    for(i = 0; i < size; i++){
        displayProduct(P[i]);
    }
}

int main(void)
{
    Product prods[] = {
        {{"PRD00001", "Corned Beef", "SH01"}, 102.00, 1000, 300},
        {{"PRD00002", "Spam", "SH01"}, 208.00, 3000, 273},
        {{"PRD00003", "Sardines in Tomato Sauce", "SH01"}, 26.00, 1235, 200},
        {{"PRD00004", "Purefoods TJ Hotdog 1KG", "FR02"}, 198.00, 1672, 20},
        {{"PRD00005", "Virginia Hotdog 1KG", "FR01"}, 192.00, 2763, 10}
    };
    
    int numProds = sizeof(prods) / sizeof(Product);
    displayProducts(prods, numProds);
    clear();
    
    Product* shelfItems = getAllShelfItems(prods, numProds, "SH01");
    displayProducts(shelfItems+1, shelfItems[0].stocks);
    clear();
    
    Product* lowStocks = getLowStockItems(prods, numProds, 2000);
    displayProducts(lowStocks+1, lowStocks[0].stocks);
    clear();
    
    int prodNdx = findProd(prods, numProds, "PRD00002");
    if(prodNdx != -1){
        displayProduct(prods[prodNdx]);
        clear();
    }else{
        printf("PRODUCT NOT FOUND");
    }
    
    updatePrices(prods, numProds, 150, 1.10);
    displayProducts(prods, numProds);
    
    return 0;
}
