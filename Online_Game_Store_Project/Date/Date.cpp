// Copyright 2025 Smirnov Nikita

#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "Date.h"

Date::Date(int d, int m, int y) {
  if (!isValidDate(d, m, y)) {
    throw std::invalid_argument("Invalid date");
  }
  _day = d;
  _month = m;
  _year = y;
}

Date::Date(const std::string& dateStr) {
  int d, m, y;
  parseDateString(dateStr, d, m, y);

  if (!isValidDate(d, m, y)) {
    throw std::invalid_argument("Invalid date");
  }

  _day = d;
  _month = m;
  _year = y;
}

int Date::getDay() const noexcept { return _day; }

int Date::getMonth() const noexcept { return _month; }

int Date::getYear() const noexcept { return _year; }

void Date::setDay(int d) {
  if (!isValidDate(d, _month, _year)) {
    throw std::invalid_argument("Invalid day");
  }
  _day = d;
}

void Date::setMonth(int m) {
  if (!isValidDate(_day, m, _year)) {
    throw std::invalid_argument("Invalid month");
  }
  _month = m;
}

void Date::setYear(int y) {
  if (!isValidDate(_day, _month, y)) {
    throw std::invalid_argument("Invalid year");
  }
  _year = y;
}

std::string Date::toString() const {
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << _day << "."
    << std::setw(2) << std::setfill('0') << _month << "."
    << std::setw(4) << std::setfill('0') << _year;
  return oss.str();
}

bool Date::operator==(const Date& other) const {
  return _day == other._day && _month == other._month && _year == other._year;
}

bool Date::operator!=(const Date& other) const {
  return !(*this == other);
}

bool Date::operator<(const Date& other) const {
  if (_year != other._year) return _year < other._year;
  if (_month != other._month) return _month < other._month;
  return _day < other._day;
}

bool Date::operator>(const Date& other) const {
  return other < *this;
}

bool Date::operator<=(const Date& other) const {
  return !(*this > other);
}

bool Date::operator>=(const Date& other) const {
  return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.toString();
  return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
  std::string dateStr;
  is >> dateStr;
  date = Date(dateStr);
  return is;
}

int Date::daysInMonth(int m) const {
  switch (m) {
  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    return 31;
  case 4: case 6: case 9: case 11:
    return 30;
  case 2:
    return 28;
  default:
    throw std::invalid_argument("Invalid month");
  }
}

bool Date::isValidDate(int d, int m, int y) const {
  if (y < 1) return false;
  if (m < 1 || m > 12) return false;
  if (d < 1 || d > daysInMonth(m)) return false;
  return true;
}

void Date::parseDateString(const std::string& dateStr, int& d, int& m, int& y) {

  if (dateStr.empty()) {
    throw std::invalid_argument("Empty date string");
  }

  std::istringstream iss(dateStr);
  char sep1, sep2;

  if (!(iss >> d >> sep1 >> m >> sep2 >> y)) {
    throw std::invalid_argument("Invalid date format");
  }

  if (sep1 != '.' || sep2 != '.') {
    throw std::invalid_argument("Date separators must be dots");
  }

  if (iss.peek() != EOF) {
    throw std::invalid_argument("Extra characters after date");
  }

  if (dateStr.length() != 10 ||
    (dateStr[2] != '.') ||
    (dateStr[5] != '.')) {
    throw std::invalid_argument("Date must be in DD.MM.YYYY format");
  }
}
