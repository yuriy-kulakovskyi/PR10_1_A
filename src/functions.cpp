#include "../include/functions.h"
#include "../include/structures.h"
#include <iostream>
#include <string>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Speciality& speciality) {
  switch (speciality) {
    case COMPUTER_SCIENCE: os << "COMPUTER_SCIENCE"; break;
    case INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES: os << "INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES"; break;
    case TOURISM: os << "TOURISM"; break;
    case CYBER_SECURITY: os << "CYBER_SECURITY"; break;
    case COMPUTER_ENGINEERING: os << "COMPUTER_ENGINEERING"; break;
    case SYSTEMS_ANALYSIS: os << "SYSTEMS_ANALYSIS"; break;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Speciality& speciality) {
  int value;
  is >> value;
  speciality = static_cast<Speciality>(value);
  return is;
}

using namespace std;

void Create(Student *s, const int N)
{
  for (int i = 0; i < N; i++)
  {
    cout << "Студент № " << i + 1 << ":" << endl;
    cin.get();
    cin.sync();
    cout << " прізвище: "; getline(cin, s[i].surname);
    cout << " курс: "; cin >> s[i].studying_year;
    cout << " спеціальність: "; cin >> s[i].speciality;
    cout << " оцінка з фізики: "; cin >> s[i].physics_mark;
    cout << " оцінка з математики: "; cin >> s[i].math_mark;
    cout << " оцінка з інформатики: "; cin >> s[i].informatics_mark;
    cout << endl;
  }
}

void Print(Student *s, const int N) {
  cout << "========================================================================================================================\n";
  cout << "|   № | Прізвище     | Курс  | Спеціальність                           | Оц(Фізика) | Оц(Математика) | Оц(Інформатика) |\n";
  cout << "------------------------------------------------------------------------------------------------------------------------\n";
  for (int i = 0; i < N; i++) {
    cout << "| " << setw(3) << right << i + 1 << " ";
    cout << "| " << setw(22) << left << s[i].surname
         << " | " << setw(4) << right << s[i].studying_year << " "
         << " | " << setw(40) << left << s[i].speciality
         << "| " << setw(10) << right << s[i].physics_mark << " "
         << "| " << setw(14) << right << s[i].math_mark << " "
         << "| " << setw(15) << right << s[i].informatics_mark << " |" << endl;
  }
  cout << "========================================================================================================================\n";
}

int Count(Student *s, const int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    if (s[i].physics_mark == 5)
      count++;
    if (s[i].math_mark == 5)
      count++;
    if (s[i].informatics_mark == 5)
      count++;
  }

  return count;
}

int CountStudents(Student *s, const int N) {
  int count = 0;

  for (int i = 0; i < N; i++) {
    if (s[i].physics_mark == 5 && s[i].math_mark == 5)
      count++;
  }

  return count;
}