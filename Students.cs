using System;
using System.Collections.Generic;

namespace Students
{
    public class Student
    {
        public string LastName { get; set; }
        public string FirstName { get; set; }
        public string MiddleName { get; set; }
        public DateTime DateOfBirth { get; set; }
        public string HomeAddress { get; set; }
        public string PhoneNumber { get; set; }

        public List<int> Credits { get; set; }
        public List<int> CourseWorks { get; set; }
        public List<int> Exams { get; set; }

        public Student()
        {
            Credits = new List<int>();
            CourseWorks = new List<int>();
            Exams = new List<int>();
        }

        public Student(string lastName, string firstName, string middleName, DateTime dateOfBirth, string homeAddress, string phoneNumber) : this()
        {
            LastName = lastName;
            FirstName = firstName;
            MiddleName = middleName;
            DateOfBirth = dateOfBirth;
            HomeAddress = homeAddress;
            PhoneNumber = phoneNumber;
        }

        public Student(string lastName, string firstName, string middleName, DateTime dateOfBirth, string homeAddress, string phoneNumber, List<int> credits, List<int> courseWorks, List<int> exams) : this(lastName, firstName, middleName, dateOfBirth, homeAddress, phoneNumber)
        {
            Credits = credits;
            CourseWorks = courseWorks;
            Exams = exams;
        }

        public void ShowStudentInfo()
        {
            Console.WriteLine($"Фамилия: {LastName}");
            Console.WriteLine($"Имя: {FirstName}");
            Console.WriteLine($"Отчество: {MiddleName}");
            Console.WriteLine($"Дата рождения: {DateOfBirth.ToShortDateString()}");
            Console.WriteLine($"Домашний адрес: {HomeAddress}");
            Console.WriteLine($"Телефонный номер: {PhoneNumber}");
            Console.WriteLine("Оценки:");
            Console.WriteLine("Зачеты: " + string.Join(", ", Credits));
            Console.WriteLine("Курсовые работы: " + string.Join(", ", CourseWorks));
            Console.WriteLine("Экзамены: " + string.Join(", ", Exams));
        }

        public override string ToString()
        {
            return $"Студент: {LastName} {FirstName} {MiddleName}\n" +
                   $"Дата рождения: {DateOfBirth.ToShortDateString()}\n" +
                   $"Домашний адрес: {HomeAddress}\n" +
                   $"Телефонный номер: {PhoneNumber}";
        }
    }
}