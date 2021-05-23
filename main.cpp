#include <iostream>
#include <string>
using namespace std;

const long JAN = 1;
const long FEB = 2;
const long MAR = 3;
const long APR = 4;
const long MAY = 5;
const long JUN = 6;
const long JUL = 7;
const long AUG = 8;
const long SEP = 9;
const long OCT = 10;
const long NOV = 11;
const long DEC = 12;

const string month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct date {
   long   year ;
   long   month ;
   long   day ;
} ;

bool is_a_leap_year(long);
long query_for_integer(string);
long return_days_in_a_month(long, long);
long return_days_in_year(long);
long query_for_integer(string);
long return_year(long julian_value); 
long return_month(long julian_value);
long return_day(long julian_value);
date *return_date(long julian_value);
void  display_date(date*); 

long return_year(long julian_value){
  long year_value = 0;
  long year_output = 1900;
  for (long year = 1900; julian_value > return_days_in_year(year); year++){
    julian_value -= return_days_in_year(year);
    year_output++;
  }
  return year_output;
}

long return_month(long julian_value){
  long month = 0;
  long year = 0;

  for (year = 1900; julian_value > return_days_in_year(year); year++){
    julian_value -= return_days_in_year(year);
  }

  for (month = 1; julian_value > return_days_in_a_month(year, month); month++){
    julian_value -= return_days_in_a_month(year, month);
  }

  return month;
}

long return_day(long julian_value){
  long month = 0;
  long year = 0;
  for (year = 1900; julian_value > return_days_in_year(year); year++){
    julian_value -= return_days_in_year(year);
  }

  for (month = 1; julian_value > return_days_in_a_month(year, month); month++){
    julian_value -= return_days_in_a_month(year, month);
  }
  return julian_value;
}

date *return_date(long julian_value){
  date *final_date;
  final_date = new date;
    final_date->year  = return_year(julian_value);
    final_date->month = return_month(julian_value);
    final_date->day   = return_day(julian_value);
  return final_date;
}

long return_days_in_year(long year){
  return ((is_a_leap_year(year)) ? 366 : 365);
}

bool is_a_leap_year(long year){
bool return_value = false;
  if ( (year % 400 ==0) || ((year % 4 == 0) && (year % 100 != 0))){
      return_value = true;
    }
  else{
      return_value = false;
    }
return return_value;
}

long query_for_integer(string prompt) {
long answer = 0;

  cout << prompt;
  cin >> answer;

  return answer;
}

long return_days_in_a_month(long year_provided, long month_provided){
  long return_value =0;
  long days_in_a_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  days_in_a_month[FEB - 1] = ((is_a_leap_year(year_provided) == true) ? 29:28);
  return_value = days_in_a_month[month_provided - 1];

return return_value;
}

int main() {
  long julian_value = 0;
  julian_value = query_for_integer("Enter a Julian value: ");
 
  date *newdate;
  newdate = return_date(julian_value);

  cout << newdate->month << "/" << newdate->day << "/" << newdate->year;
  
return 0;
}