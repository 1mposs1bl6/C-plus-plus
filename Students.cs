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

        public double CalculateAverageGrade()
        {
            int totalCredits = Credits.Sum();
            int totalCourseWorks = CourseWorks.Sum();
            int totalExams = Exams.Sum();
            int totalGrades = totalCredits + totalCourseWorks + totalExams;

            if (totalGrades == 0)
            {
                return 0;
            }

            return (double)(totalCredits + totalCourseWorks + totalExams) / totalGrades;
        }

        public static bool operator true(Student student)
        {
            return student.CalculateAverageGrade() >= 7;
        }

        public static bool operator false(Student student)
        {
            return student.CalculateAverageGrade() < 7;
        }

        public static bool operator >(Student student1, Student student2)
        {
            return student1.CalculateAverageGrade() > student2.CalculateAverageGrade();
        }

        public static bool operator <(Student student1, Student student2)
        {
            return student1.CalculateAverageGrade() < student2.CalculateAverageGrade();
        }

        public static bool operator ==(Student student1, Student student2)
        {
            if (ReferenceEquals(student1, null) || ReferenceEquals(student2, null))
            {
                return ReferenceEquals(student1, student2);
            }

            return student1.CalculateAverageGrade() == student2.CalculateAverageGrade();
        }

        public static bool operator !=(Student student1, Student student2)
        {
            return !(student1 == student2);
        }
    }

    public class Group
    {
        public string Name { get; set; }
        public List<Student> Students { get; set; }

        public Group(string name)
        {
            Name = name;
            Students = new List<Student>();
        }

        public static bool operator true(Group group)
        {
            return group.Students.Count > 0;
        }

        public static bool operator false(Group group)
        {
            return group.Students.Count == 0;
        }

        public static bool operator >(Group group1, Group group2)
        {
            return group1.Students.Count > group2.Students.Count;
        }

        public static bool operator <(Group group1, Group group2)
        {
            return group1.Students.Count < group2.Students.Count;
        }

        public static bool operator ==(Group group1, Group group2)
        {
            if (ReferenceEquals(group1, null) || ReferenceEquals(group2, null))
            {
                return ReferenceEquals(group1, group2);
            }

            return group1.Students.Count == group2.Students.Count;
        }

        public static bool operator !=(Group group1, Group group2)
        {
            return !(group1 == group2);
        }

        public Student this[int index]
        {
            get
            {
                if (index < 0 || index >= Students.Count)
                {
                    throw new IndexOutOfRangeException();
                }

                return Students[index];
            }
        }
    }
}