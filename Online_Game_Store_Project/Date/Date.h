// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_DATE_DATE_H_
#define ONLINE_GAME_STORE_PROJECT_DATE_DATE_H_

#include <iostream>
#include <string>

class Date {
  int _day;
  int _month;
  int _year;

 public:
   Date(int d = 1, int m = 1, int y = 1);
   explicit Date(const std::string& dateStr);

   int getDay() const noexcept;
   int getMonth() const noexcept;
   int getYear() const noexcept;

   void setDay(int d);
   void setMonth(int m);
   void setYear(int y);

   std::string toString() const;

   bool operator==(const Date& other) const;

   bool operator!=(const Date& other) const;

   bool operator<(const Date& other) const;

   bool operator>(const Date& other) const;

   bool operator<=(const Date& other) const;

   bool operator>=(const Date& other) const;

   friend std::ostream& operator<<(std::ostream& os, const Date& date);

   friend std::istream& operator>>(std::istream& is, Date& date);

 private:
  int daysInMonth(int m) const;
  bool isValidDate(int d, int m, int y) const;
  static void parseDateString(const std::string& dateStr, int& d,
    int& m, int& y);
};
#endif  // ONLINE_GAME_STORE_PROJECT_DATE_DATE_H_
