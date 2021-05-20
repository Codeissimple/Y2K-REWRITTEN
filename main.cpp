#include <iostream>
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

long compute_julian_day(long, long, long);
bool is_day_valid(long, long);
bool is_month_valid(long);
bool is_day_valid(long);
bool is_a_leap_year(long);
long query_for_integer(string);
long query_for_valid_day(long month) ;
long query_for_valid_month();
long return_days_in_month(long, long);
long return_days_in_year(long);
long query_for_integer(string);
long return_year(long julian_value); 
long return_month(long julian_value);
long return_day(long julian_value);
date *return_date(long julian_value);

long return_year(long julian_value){
  long year = 1;
  long year_value = 0;

  for (long year; julian_value - 365 > 0; year++){
    if (is_a_leap_year(year) == false){
      year_value = julian_value - 365;
      
    }
    else{
      year_value = julian_value - 366;
      
    }
  }
  return year_value;
}



// OLD PROGRAm code
long query_for_integer(string prompt) {
long answer = 0;

  cout << prompt;
  cin >> answer;

  return answer;
}

bool is_month_valid(long month){
bool return_value = false;
  if (month >= 1 && month <= 12){
    return_value = true;
  }
  else{
    return_value = false;
  }
  return return_value;
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

long return_days_in_year(long year){
  return ((is_a_leap_year(year)) ? 366 : 365);
}

long return_days_in_a_month(long year_provided, long month_provided){
  long return_value =0;
  long days_in_a_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  days_in_a_month[FEB - 1] = ((is_a_leap_year(year_provided) == true) ? 29:28);
  return_value = days_in_a_month[month_provided - 1];

return return_value;
}

long compute_julian_day(long year_provided, long month_provided, long day_provided){

long julian_number_computed = 0;
long julian_number = 0;

  for(long year = 1900; year < year_provided; year ++){
    julian_number_computed += return_days_in_year(year);
  }

  for(long month = JAN; month < month_provided; month ++){
    julian_number_computed += return_days_in_a_month(year_provided, month);
  }

  julian_number_computed += day_provided;
  
  return julian_number_computed;
}

long query_for_valid_month(){
  long month = 0;
  do 
    month = query_for_integer("Enter a month: ");
  while (is_month_valid(month) == false);
return month;
}

bool is_day_valid(long year, long month, long day){
  if( day < 1 || day > return_days_in_a_month( year, month))
    return false;
  else
    return true;
}


long query_for_valid_day(long year, long month){
  long day = 0;
  do
     day = query_for_integer("Enter a day: ");
  while (is_day_valid(year, month, day) == false);
return day;
}


int main() {

   long julian_value = query_for_integer("Enter a Julian value: ") ;

  cout << return_year(julian_value);

  
   return 1 ;
}