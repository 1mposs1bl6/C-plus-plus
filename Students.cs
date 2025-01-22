using System;
using System.Collections.Generic;
using System.Linq;

namespace Students
{
    public interface ICloneable
    {
        object Clone();
    }

    public class Student : ICloneable
    {
        private string _lastName;
        private string _firstName;
        private string _middleName;
        private DateTime _dateOfBirth;
        private string _homeAddress;
        private string _phoneNumber;

        public string LastName
        {
            get { return _lastName; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Фамилия не может быть пустой или состоять только из пробелов.");
                }
                _lastName = value;
            }
        }
        public string FirstName
        {
            get { return _firstName; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Имя не может быть пустым или состоять только из пробелов.");
                }
                _firstName = value;
            }
        }
        public string MiddleName
        {
            get { return _middleName; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Отчество не может быть пустым или состоять только из пробелов.");
                }
                _middleName = value;
            }
        }
        public DateTime DateOfBirth
        {
            get { return _dateOfBirth; }
            set
            {
                if (value > DateTime.Now)
                {
                    throw new ArgumentException("Дата рождения не может быть в будущем.");
                }
                _dateOfBirth = value;
            }
        }
        public string HomeAddress
        {
            get { return _homeAddress; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Домашний адрес не может быть пустым или состоять только из пробелов.");
                }
                _homeAddress = value;
            }
        }
        public string PhoneNumber
        {
            get { return _phoneNumber; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Телефонный номер не может быть пустым или состоять только из пробелов.");
                }
                _phoneNumber = value;
            }
        }

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

        public class SortByAverageGrade : IComparer<Student>
        {
            public int Compare(Student x, Student y)
            {
                return x.CalculateAverageGrade().CompareTo(y.CalculateAverageGrade());
            }
        }

        public class SortByFullName : IComparer<Student>
        {
            public int Compare(Student x, Student y)
            {
                return string.Compare(x.LastName + " " + x.FirstName + " " + x.MiddleName, y.LastName + " " + y.FirstName + " " + y.MiddleName);
            }
        }

        public object Clone()
        {
            Student clone = new Student(LastName, FirstName, MiddleName, DateOfBirth, HomeAddress, PhoneNumber);
            clone.Credits = new List<int>(Credits);
            clone.CourseWorks = new List<int>(CourseWorks);
            clone.Exams = new List<int>(Exams);
            return clone;
        }
    }

    public class Group : ICloneable, IEnumerable<Student>
    {
        private string _name;
        public string Name
        {
            get { return _name; }
            set
            {
                if (string.IsNullOrWhiteSpace(value))
                {
                    throw new ArgumentException("Название группы не может быть пустым или состоять только из пробелов.");
                }
                _name = value;
            }
        }
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

        public IEnumerator<Student> GetEnumerator()
        {
            foreach (Student student in Students)
            {
                yield return student;
            }
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public object Clone()
        {
            Group clone = new Group(Name);
            clone.Students = new List<Student>();
            foreach (Student student in Students)
            {
                clone.Students.Add((Student)student.Clone());
            }
            return clone;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Создать объект группы и студентов
            Group group = new Group("Группа 1");
            group.Students.Add(new Student("Иванов", "Иван", "Иванович", new DateTime(2000, 1, 1), "г. Москва", "+7 (999) 123-45-67", new List<int> { 5, 4, 5 }, new List<int> { 4, 5 }, new List<int> { 5, 4, 5 }));
            group.Students.Add(new Student("Петров", "Петр", "Петрович", new DateTime(2001, 2, 2), "г. Санкт-Петербург", "+7 (888) 123-45-67", new List<int> { 4, 5, 4 }, new List<int> { 5, 4 }, new List<int> { 4, 5, 4 }));
            group.Students.Add(new Student("Сидоров", "Сидор", "Сидорович", new DateTime(2002, 3, 3), "г. Новосибирск", "+7 (777) 123-45-67", new List<int> { 3, 4, 3 }, new List<int> { 4, 3 }, new List<int> { 3, 4, 3 }));

            // Выполнить сортировку по среднему баллу
            group.Students.Sort(new Student.SortByAverageGrade());
            Console.WriteLine("Сортировка по среднему баллу:");
            foreach (Student student in group)
            {
                Console.WriteLine(student);
            }

            // Выполнить сортировку по ФИО
            group.Students.Sort(new Student.SortByFullName());
            Console.WriteLine("\nСортировка по ФИО:");
            foreach (Student student in group)
            {
                Console.WriteLine(student);
            }

            Console.ReadKey();
        }
    }
}