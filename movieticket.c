#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
char thname_arr[4][10] = {"Inox","PVR","Carnival","Cinemax"};
float price_arr[3] = {250,300,350};
char seat_arr[3][7] = {"Bronze","Silver","Gold"};
char date_arr[7][10] =
{"30/08/21","31/08/21","1/09/21","2/09/21","3/09/21","4/09/21","5/09/21"};
char movie_arr[5][10] = {"Shershaah","Mimi","Hungama 2","Toofaan","Dial 100"};

date:
printf("Select Date - \n");
for(int i=0;i<7;i++) {
printf("%d.%s\n",i+1,date_arr[i]);
}
int date;
scanf("%d",&date);
if(date > 7) {
printf("Invalid Input\n\n");
goto date;
}

movie:
printf("Select Movie - \n");
for(int i=0;i<5;i++) {
printf("%d.%s\n",i+1,movie_arr[i]);
}
int moviename;

scanf("%d",&moviename);
if(moviename > 5) {
printf("Invalid Input\n\n");
goto movie;
}

theatre:
printf("Select Theatre - \n");
for(int i=0;i<4;i++) {
printf("%d.%s\n",i+1,thname_arr[i]);
}
int thname;
scanf("%d",&thname);
if(thname > 4) {
printf("Invalid Input\n\n");
goto theatre;
}

printf("\n*SCREEN THIS SIDE*\n");
int arr[10][10];
int row,col;
int t1=0,t2=0;
for(int i=1;i<=10;i++){
for(int j=1;j<=10;j++){
arr[i][j]=0;
}
}
for(int i=1;i<=10;i++){
for(int j=1;j<=10;j++){
if(i==10){

printf("\x1b[32m");
}
if(i==9 || i==8 || i==7 || i==6){
printf("\x1b[33m");
}
if(i==5 || i==4 || i==3 || i==2 || i==1){
printf("\x1b[36m");
}
printf("%d",arr[i][j]);
printf("\x1b[0m");
}
printf("\n");
}

int seattype;
seat:
printf("Select Seat Type - \n");
for(int i=0;i<3;i++) {
printf("%d.%s = %f\n",i+1,seat_arr[i],price_arr[i]);
}
scanf("%d",&seattype);
if(thname > 4) {
printf("Invalid Input\n\n");
goto seat;
}
float price;
switch(seattype) {
case 1 :
price = price_arr[0];
printf("Bronze Class :-\n");

for(int i=1;i<=10;i++){
printf(" %d",i);
}
printf("\n");
for(int i=1;i<=5;i++){
printf("%d",i);
for(int j=1;j<=10;j++){
printf("\x1b[36m");
printf(" %d ",arr[i][j]);
printf("\x1b[0m");
}
printf("\n");
}
printf("\n");
break;
case 2 :
price = price_arr[1];
printf("Silver Class :-\n");
for(int i=1;i<=10;i++){
printf(" %d",i);
}
printf("\n");
for(int i=6;i<=9;i++){
printf("%d",i);
for(int j=1;j<=10;j++){
printf("\x1b[33m");
printf(" %d ",arr[i][j]);
printf("\x1b[0m");
}
printf("\n");

}
printf("\n");
break;
case 3 :
price = price_arr[2];
printf("Gold Class :-\n");
printf(" ");
for(int i=1;i<=10;i++){
printf(" %d",i);
}
printf("\n");
for(int i=10;i<=10;i++){
printf("%d",i);
for(int j=1;j<=10;j++){
printf("\x1b[32m");
printf(" %d ",arr[i][j]);
printf("\x1b[0m");
}
printf("\n");
}
printf("\n");
break;
default :
printf("Invalid\n");
goto seat;
}

int num,noticket;
printf("Enter number of tickets : ");
scanf("%d",&num);

noticket = num;
while(num>0){
printf("\nEnter seat - \n");
printf("Enter row :");
scanf(" %d",&row);
printf("Enter col :");
scanf(" %d",&col);
if(row < 1 || row > 10 || col < 1 || col > 10 ){
printf("\nEnter another seat -\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
}
if(seattype==1){
if(row>5 ){
printf("Seat from another class selected (Choose row between 1-5)\n");
printf("Enter correct seat\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
}
}
if(seattype==2){
if(row>9 && row<6){
printf("Seat from another class selected (Choose row between 6-9)\n");
printf("Enter correct seat\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
}
}
if(seattype==3){
if(row!=10){

printf("Seat from another class selected (Choose between 1-5)\n");
printf("Enter correct seat\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
}
}
if(arr[row][col]==0){
arr[row][col]=1;
}
else if(arr[row][col]==1){
printf("Enter another seat -\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
if(seattype==1){
if(row>5){
printf("Seat from another class selected\n");
printf("Enter correct seat\n");
printf("Enter row :");scanf("%d",&row);
printf("Enter col :");scanf("%d",&col);
}
}
if(seattype==2){
if(row>9 && row<6){
printf("Seat from another class selected (Choose row between 6-9)\n");
printf("Enter correct seat\n");
printf("\nEnter row :");scanf("%d",&row);
printf("\nEnter col :");scanf("%d",&col);
}
}
if(seattype==3){

if(row!=10){
printf("Seat from another class selected (Choose between 1-5)\n");
printf("Enter correct seat\n");
printf("\n\nEnter row :");scanf("%d",&row);
printf("\nEnter col :");scanf("%d",&col);
}
}
if(arr[row][col]==0){
arr[row][col]=1;
}
}
num--;
}

float cost;
if(num<1){
printf("\n\n***************************\n");
switch(date) {
case 1:
cost = price*noticket; break;
case 2:
cost = price*noticket; break;
case 3:
cost = price*noticket;
printf("Buzzinga! Weekday offer, you get 1 medium size popcorn bucket! Use
code:x2tPL at the counter");
break;
case 4:
cost = price*noticket; break;
case 5:
cost = price*noticket; break;

case 6:
printf("Yay! You get 10%% off!");
cost = price*noticket*0.9;
break;
case 7:
printf("Yay! You get 10%% off!");
cost = price*noticket*0.9;
break;
default:
printf("Invalid Input");
}
printf("\n***************************");
printf("\nTheatre Name : %s",thname_arr[thname-1]);
printf("\nMovie Name : %s",movie_arr[moviename-1]);
printf("\nMovie Date : %s",date_arr[date-1]);
printf("\nCategory : %s",seat_arr[seattype-1]);
printf("\nSeat ID : ");
for(int i=1;i<=10;i++){
for(int j=1;j<=10;j++){
if(arr[i][j]==1){
printf("%d.%d ",i,j);
}
}
}
printf("\nCost : %f",cost);
printf("\n***************************");
}
return 0;
}
