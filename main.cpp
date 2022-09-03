
//  lab2.cpp
//  lab2OOPS
//
//  Created by Ragupathi on 02/08/2022.
//
/*
 
 Write a C++ program to implement a time class. It has private hours, minutes, and seconds data members. There are two options to create a clock namely,
 Create
 Create and Set Time
 Creation option calls a default constructor that sets all the private members to 0. The second option gets the hour, minutes, and seconds value from the user; creates, and calls a default constructor to initialize all private data members. A destructor is called to destroy the memory allocated to time class objects once they go out of scope. The program has the following Menu,

 Set Time
 Print Standard Time (AM or PM)
 Print Universal Time (24 hours)
 Print Indian Start Time (24 hours)
 Print Pacific Standard Time (AM or PM)
 Exit

 Maintain proper boundary conditions and follow coding best practices.

 
 */

#include <iostream>
using namespace std;


class Time {
private:
    int hours;
    int minutes;
    int seconds;
    
public:
    Time(){         // default constructor --- set
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    
    Time(int Hourss, int Min , int Sec){        //parameterized constructor --- set + create
        hours = Hourss;
        minutes = Min;
        seconds = Sec;
    }
    
    //setter function:
    void setTime(int h, int min, int sec){
        hours = h;
        minutes = min;
        seconds = sec;
    }
    
    //getter functions:
    int getHours(){
        return hours;
    }
    int getMinutes() {
        return minutes;
    }
    int getSeconds() {
        return seconds;}
    
    //destructor:
    ~Time() {
        cout<< "Destructor executed"<<endl;
    }
    
    //friend functions:
    friend Time createTime(Time T1);
    friend void print_standard(Time T1);
    friend void print_universal(Time T1);
    friend void print_indian(Time T1);
    friend void print_pacific(Time T1);
    friend void display(Time T1);
};

//display function
void display(Time T1){
   // cout<< T1.hours << ":" << T1.minutes << ":" << T1.seconds << endl;
    //if hours, min and seconds are greater than 9, we can display directly
    if(T1.hours>9 && T1.minutes >9 && T1.seconds >9){
    cout <<"Time is = " << T1.hours << ":" << T1.minutes << ":" << T1.seconds << endl;
    }
    // if only minutes is less that 10
    else if (T1.minutes <10 && T1.hours > 9 && T1.seconds >9){
        cout <<"Time is = " << T1.hours << ":0" << T1.minutes << ":" << T1.seconds << endl;
    }
    // if only seconds is less than 10
    else if (T1.seconds <10 && T1.hours > 9 && T1.minutes > 9){
        cout <<"Time is = " << T1.hours << ":" << T1.minutes << ":0" << T1.seconds << endl;
    }
    //if only hours is less than 10
    else if (T1.hours < 10 && T1.minutes > 9 && T1.seconds > 9 ){
        cout <<"Time is = 0" << T1.hours << ":" << T1.minutes << ":" << T1.seconds << endl;
    }
    // if minutes and seconds are less than 10
    else if (T1.minutes <10 && T1.seconds <10 && T1.hours> 9){
        cout <<"Time is = " << T1.hours << ":0" << T1.minutes << ":0" << T1.seconds << endl;
    }
    // if minutes and hours are less than 10
    else if (T1.minutes <10 && T1.hours < 10 && T1.seconds > 9 ){
        cout <<"Time is = 0" << T1.hours << ":0" << T1.minutes << ":" << T1.seconds << endl;
    }
    //if seconds and hours are less than 10
    else if(T1.seconds <10 && T1.hours < 10 && T1.minutes > 9){
        cout <<"Time is = 0" << T1.hours << ":" << T1.minutes << ":0" << T1.seconds << endl;
    }
    //if all are less than 10
    else {
        cout <<"Time is = 0" << T1.hours << ":0" << T1.minutes << ":0" << T1.seconds << endl;
    }
}

//print in standard form AM or PM
void print_standard(Time T1) {
    int HOURS;
    if(T1.hours>12) {
        HOURS = T1.hours - 12;
        //if hours, min and seconds are greater than 9, we can display directly
        if(HOURS>9 && T1.minutes >9 && T1.seconds >9){
        cout <<" Standard Time is = " << HOURS << ":" << T1.minutes << ":" << T1.seconds << "PM" << endl;
        }
        // if only minutes is less that 10
        else if (T1.minutes <10 && HOURS > 9 && T1.seconds >9){
            cout <<" Standard Time is = " << HOURS << ":0" << T1.minutes << ":" << T1.seconds << "PM" << endl;
        }
        // if only seconds is less than 10
        else if (T1.seconds <10 && HOURS > 9 && T1.minutes > 9){
            cout <<" Standard Time is = " << HOURS << ":" << T1.minutes << ":0" << T1.seconds << "PM" << endl;
        }
        //if only hours is less than 10
        else if (HOURS < 10 && T1.minutes > 9 && T1.seconds > 9 ){
            cout <<" Standard Time is = 0" << HOURS << ":" << T1.minutes << ":" << T1.seconds << "PM" << endl;
        }
        // if minutes and seconds are less than 10
        else if (T1.minutes <10 && T1.seconds <10 && HOURS > 9){
            cout <<" Standard Time is = " << HOURS << ":0" << T1.minutes << ":0" << T1.seconds << "PM" << endl;
        }
        // if minutes and hours are less than 10
        else if (T1.minutes <10 && HOURS < 10 && T1.seconds > 9 ){
            cout <<" Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":" << T1.seconds << "PM" << endl;
        }
        //if seconds and hours are less than 10
        else if(T1.seconds <10 && HOURS < 10 && T1.minutes > 9){
            cout <<" Standard Time is = 0" << HOURS << ":" << T1.minutes << ":0" << T1.seconds << "PM" << endl;
        }
        //if all are less than 10
        else {
            cout <<" Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":0" << T1.seconds << "PM" << endl;
        }
    }
    else {
       // cout <<"Standard time is = "<<T1.hours << ":" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        //if hours, min and seconds are greater than 9, we can display directly
        if(T1.hours>9 && T1.minutes >9 && T1.seconds >9){
        cout <<"Time is = " << T1.hours << ":" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        // if only minutes is less that 10
        else if (T1.minutes <10 && T1.hours > 9 && T1.seconds >9){
            cout <<"Time is = " << T1.hours << ":0" << T1.minutes << ":" << T1.seconds <<"AM" << endl;
        }
        // if only seconds is less than 10
        else if (T1.seconds <10 && T1.hours > 9 && T1.minutes > 9){
            cout <<"Time is = " << T1.hours << ":" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        //if only hours is less than 10
        else if (T1.hours < 10 && T1.minutes > 9 && T1.seconds > 9 ){
            cout <<"Time is = 0" << T1.hours << ":" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        // if minutes and seconds are less than 10
        else if (T1.minutes <10 && T1.seconds <10 && T1.hours> 9){
            cout <<"Time is = " << T1.hours << ":0" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        // if minutes and hours are less than 10
        else if (T1.minutes <10 && T1.hours < 10 && T1.seconds > 9 ){
            cout <<"Time is = 0" << T1.hours << ":0" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        //if seconds and hours are less than 10
        else if(T1.seconds <10 && T1.hours < 10 && T1.minutes > 9){
            cout <<"Time is = 0" << T1.hours << ":" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        //if all are less than 10
        else {
            cout <<"Time is = 0" << T1.hours << ":0" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
    }
}

//Print in Universal Time == GMT
void print_universal(Time T1){
    display(T1);
}

//Print in Indian Standard Time
void print_indian(Time T1){
    int HOURS, MINUTES;
    HOURS = 5 + T1.hours;
    MINUTES = 30 + T1.minutes;
    if(MINUTES >=60){
        HOURS++;
        MINUTES=MINUTES%60;
    }
    if(HOURS>=24){
        HOURS = HOURS%24;
    }
    //cout << "Indian Standard Time is = " << HOURS << ":" << MINUTES << ":" << T1.seconds << endl;
    
    if(HOURS>9 && MINUTES >9 && T1.seconds >9){
    cout <<"Indian Standard Time is = " << HOURS << ":" << MINUTES << ":" << T1.seconds << endl;
    }
    // if only minutes is less that 10
    else if (MINUTES <10 && HOURS > 9 && T1.seconds >9){
        cout <<"Indian Standard Time is = " << HOURS << ":0" << MINUTES << ":" << T1.seconds << endl;
    }
    // if only seconds is less than 10
    else if (MINUTES <10 && HOURS > 9 && T1.minutes > 9){
        cout <<"Indian Standard Time is = " << HOURS << ":" << MINUTES << ":0" << T1.seconds << endl;
    }
    //if only hours is less than 10
    else if (HOURS < 10 && MINUTES > 9 && T1.seconds > 9 ){
        cout <<"Indian Standard Time is = 0" << HOURS << ":" << MINUTES << ":" << T1.seconds << endl;
    }
    // if minutes and seconds are less than 10
    else if (MINUTES <10 && T1.seconds <10 && HOURS > 9){
        cout <<"Indian Standard Time is = " << HOURS << ":0" << MINUTES << ":0" << T1.seconds << endl;
    }
    // if minutes and hours are less than 10
    else if (MINUTES <10 && HOURS < 10 && T1.seconds > 9 ){
        cout <<"Indian Standard Time is = 0" << HOURS << ":0" << MINUTES << ":" << T1.seconds << endl;
    }
    //if seconds and hours are less than 10
    else if(T1.seconds <10 && HOURS < 10 && MINUTES){
        cout <<"Indian Standard Time is = 0" << HOURS << ":" << MINUTES << ":0" << T1.seconds << endl;
    }
    //if all are less than 10
    else {
        cout <<"Indian Standard Time is = 0" << HOURS << ":0" << MINUTES << ":0" << T1.seconds << endl;
}
}

//Print in Pacific Standard Time
void print_pacific(Time T1){
    int HOURS = T1.hours - 8;
    if(HOURS < 0){
        HOURS+=24;
    }
    if(HOURS > 12){
        HOURS = HOURS - 12;
    // to display in XX:XX:XX format:
    //if hours, min and seconds are greater than 9, we can display directly
    if(HOURS > 9 && T1.minutes > 9 && T1.seconds > 9){
        cout <<"Pacific Standard Time is = " << HOURS << ":" << T1.minutes << ":" << T1.seconds << "PM" << endl;
    }
    // if only minutes is less that 10
    else if (T1.minutes < 10 && HOURS > 9 && T1.seconds >9){
        cout <<"Pacific Standard Time is = " << HOURS << ":0" << T1.minutes << ":" << T1.seconds << "PM" << endl;
    }
    // if only seconds is less than 10
    else if (T1.seconds < 10 && HOURS > 9 && T1.minutes > 9){
        cout <<"Pacific Standard Time is = " << HOURS << ":" << T1.minutes << ":0" << T1.seconds << "PM" << endl;
    }
    //if only hours is less than 10
    else if (HOURS < 10 && T1.minutes > 9 && T1.seconds > 9 ){
        cout <<"Pacific Standard Time is = 0" << HOURS << ":" << T1.minutes << ":" << T1.seconds << "PM" << endl;
    }
    // if minutes and seconds are less than 10
    else if (T1.minutes < 10 && T1.seconds < 10 && HOURS > 9){
        cout <<"Pacific Standard Time is = " << HOURS << ":0" << T1.minutes << ":0" << T1.seconds <<"PM" << endl;
    }
    // if minutes and hours are less than 10
    else if (T1.minutes < 10 && HOURS < 10 && T1.seconds > 9 ){
        cout <<"Pacific Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":" << T1.seconds <<"PM" << endl;
    }
    //if seconds and hours are less than 10
    else if(T1.seconds < 10 && HOURS < 10 && T1.minutes > 9){
        cout <<"Pacific Standard Time is = 0" << HOURS << ":" << T1.minutes << ":0" << T1.seconds <<"PM" << endl;
    }
    //if all are less than 10
    else {
        cout <<"Pacific Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":0" << T1.seconds <<"PM" << endl;
    }
        
    }
    else {
        if(HOURS > 9 && T1.minutes > 9 && T1.seconds > 9){
            cout <<"Pacific Standard Time is = " << HOURS << ":" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        // if only minutes is less that 10
        else if (T1.minutes < 10 && HOURS > 9 && T1.seconds >9){
            cout <<"Pacific Standard Time is = " << HOURS << ":0" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        // if only seconds is less than 10
        else if (T1.seconds < 10 && HOURS > 9 && T1.minutes > 9){
            cout <<"Pacific Standard Time is = " << HOURS << ":" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        //if only hours is less than 10
        else if (HOURS < 10 && T1.minutes > 9 && T1.seconds > 9 ){
            cout <<"Pacific Standard Time is = 0" << HOURS << ":" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        // if minutes and seconds are less than 10
        else if (T1.minutes < 10 && T1.seconds < 10 && HOURS > 9){
            cout <<"Pacific Standard Time is = " << HOURS << ":0" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        // if minutes and hours are less than 10
        else if (T1.minutes < 10 && HOURS < 10 && T1.seconds > 9 ){
            cout <<"Pacific Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":" << T1.seconds << "AM" << endl;
        }
        //if seconds and hours are less than 10
        else if(T1.seconds < 10 && HOURS < 10 && T1.minutes > 9){
            cout <<"Pacific Standard Time is = 0" << HOURS << ":" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
        //if all are less than 10
        else {
            cout <<"Pacific Standard Time is = 0" << HOURS << ":0" << T1.minutes << ":0" << T1.seconds << "AM" << endl;
        }
    }
}

//To create and set time
Time createTime(Time T1) {
    int option_setting, Hours, Minutes, Seconds;
    cout << "Do you wish to:\nCreate : press 1\nCreate and Set : press 2\nFor Reset : press 3\n" << endl;
    cin >> option_setting;
    if(option_setting == 1 || option_setting == 3){
        //time is set already
        display(T1);
    }
    else if (option_setting == 2){
        do {
            cout << "please provide the hours\n" <<endl;
            cin >> Hours;
        } while (Hours < 0 || Hours > 23);
        do {
            cout << "please provide the minutes\n" << endl;
            cin >> Minutes;
        } while(Minutes < 0 || Minutes > 59);
        do {
            cout << "please provide the seconds\n" << endl;
            cin >> Seconds;
        }while(Seconds < 0 || Seconds > 59);
        T1.setTime(Hours, Minutes, Seconds);
        display(T1);
    }
    else {
        cout << "please enter 1 or 2 or 3" <<endl;
    }
    return T1;
}

int main() {
    int option;
    Time T;
    cout << "This program will set and print time according to your inputs";
    
    printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
    cin >> option;
    while (option >0){
        if(option == 1){
            T = createTime(T);
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
        else if (option == 2){
            print_standard(T);
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
        else if (option == 3){
            print_universal(T);
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
        else if (option == 4){
            print_indian(T);
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
        else if (option ==5){
            print_pacific(T);
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
        else if (option == 6){
            cout << "you've successfully exited the program :)" << endl;
            break;
        }
   
        else {
            cout << "please press any digit from 1 to 6" << endl;
            printf("Do you wish to:\nSet Time : press 1\nPrint Standard Time (AM or PM) : press 2\nPrint Universal Time (24 hours) : press 3\nPrint Indian Start Time (24 hours) : press 4\nPrint Pacific Standard Time (AM or PM) : press 5\nExit : press 6\n\n");
            cin >> option;
        }
    }
  
    return(0);
}
