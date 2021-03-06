/*
*
* Copyright (c) 2022 Melvin Jones Repol (mrepol742.github.io). All rights reserved.
*
* License under the GNU General Public License, Version 3.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://www.gnu.org/licenses/gpl-3.0.en.html
*
* Unless required by the applicable law or agreed in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

// Video demo at https://mrepol742.github.io/Mini-Restuarant-System/ZeroTeaTime.mp4
// Live demo at https://onlinegdb.com/ZWLo37958

#include <stdio.h>
#include <time.h>

void delay(int ms);
void menu();
void input();
void receipt();

char food[][20] = {"Lemon Pie", "Iced Coffee", "Pork Cutlet Bowl", "Takiyaki", "Yaki Dango", "Ramen", "Onigiri", "Curry", "Pocky"};
int price[10] = {59, 49, 99, 79, 89, 59, 99, 59, 79};
int orders[99];
char asd[] = "#############";

int main() {
    delay(100);
    printf("%s\n\n", asd);
    delay(100);
    printf("\t--- Zero's Tea Time ---");
    delay(150);
    printf("\n\n%s", asd);
    delay(500);
    printf("\n\nWelcome to our restuarant!\n");
    delay(500);
    printf("Here's our menu:\n");
    delay(500);
    menu();
    printf("\nEnter the number you like to order: ");
    delay(500);
    input();
    
    return 0;
}

int length(int *p) { 
	int s = 0; 
    // eren
	while(*p != '\0') { 
		s++; 
		p++; 
	} 
	return s; 
} 

void receipt() {
    delay(200);
    int i, sum = 0;
    printf("\n\n#############");
    delay(150);
    printf("\n\tRECEIPT");
    for (i = 0; i < length(orders)-1; i++) {
        sum += price[orders[i]];
        printf("\n\t\t%s %dP", food[orders[i]], price[orders[i]]);
        delay(250);
    } 
    delay(500);
    printf("\n\n\t\tThe total amount is: %dP\n", sum);
    delay(500);
    printf("\n\t\t----");
    delay(500);
    printf("\n\t\tEnter Payment: ");
    int pay;
    scanf("%d", &pay);
    delay(500);
    printf("\t\t----");
    delay(500);
    if (pay >= sum) {
        int change = pay - sum;
        printf("\n\n\t\tChange:  %dP\n", change);
    } else {
        int bal = sum - pay;
        printf("\n\n\t\tBalance: %dP\n", bal);
    }
    delay(500);
    printf("#############\n");
    printf("\n\n\n\t\t ===== THANK YOU FOR PURCHASING =====\n\n\n\n");
}

void input() {
    int i;
    while (1) {
        i++;
        int or;
        scanf("%d", &or);
        orders[i -1 ] = or -1;
        // debug
      //  printf("Append: %d", orders[i]);
       delay(100);
        if (or == 0) {
            receipt();
            break;
        } else {
            printf("  Added %s to the list.", food[orders[i -1]]);
            printf("\n\nWanna add more? ");
        }
    }
}

void menu() {
    int i;
    for (i = 0; i < 9; i++) {
        printf("%d. %s - %dP\n", i + 1, food[i], price[i]);
        delay(200);
    }
    printf("Enter '0' to finished the order.\n");
}

void delay(int ms) {
    long pe;
    clock_t now, then;
    pe = ms * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now-then) < pe) {
        now = clock();
    }
}