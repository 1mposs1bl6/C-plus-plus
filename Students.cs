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

        // Делегат для фильтрации студентов
        public delegate bool StudentFilter(Student student);

        // Метод фильтрации студентов
        public List<Student> FilterStudents(StudentFilter filter)
        {
            List<Student> filteredStudents = new List<Student>();
            foreach (Student student in Students)
            {
                if (filter(student))
                {
                    filteredStudents.Add(student);
                }
            }
            return filteredStudents;
        }
    }

    class Program
    {
        delegate void MenuAction();

        static void Main(string[] args)
        {
            // Создать объект группы и студентов
            Group group = new Group("Группа 1");
            group.Students.Add(new Student("Иванов", "Иван", "Иванович", new DateTime(2000, 1, 1), "г. Москва", "+7 (999) 123-45-67", new List<int> { 5, 4, 5 }, new List<int> { 4, 5 }, new List<int> { 5, 4, 5 }));
            group.Students.Add(new Student("Петров", "Петр", "Петрович", new DateTime(2001, 2, 2), "г. Санкт-Петербург", "+7 (888) 123-45-67", new List<int> { 4, 5, 4 }, new List<int> { 5, 4 }, new List<int> { 4, 5, 4 }));
            group.Students.Add(new Student("Сидоров", "Сидор", "Сидорович", new DateTime(2002, 3, 3), "г. Новосибирск", "+7 (777) 123-45-67", new List<int> { 3, 4, 3 }, new List<int> { 4, 3 }, new List<int> { 3, 4, 3 }));

            // Создать цепочку делегатов
            MenuAction[] actions = new MenuAction[]
            {
                AddStudentToGroup,
                RemoveStudentFromGroup,
                ShowExcellentStudents,
                ShowStudentsWithFailingGrades
            };

            while (true)
            {
                Console.WriteLine("Меню:");
                Console.WriteLine("0. Добавить студента в группу");
                Console.WriteLine("1. Удалить студента из группы");
                Console.WriteLine("2. Показать всех отличников");
                Console.WriteLine("3. Показать всех студентов, у которых есть двойки по экзаменам");
                Console.WriteLine("4. Выход");

                Console.Write("Введите номер пункта меню: ");
                int choice;
                if (int.TryParse(Console.ReadLine(), out choice) && choice >= 0 && choice <= 4)
                {
                    if (choice == 4)
                    {
                        break;
                    }

                    // Вызвать соответствующий метод из цепочки делегатов
                    actions[choice]();
                }
                else
                {
                    Console.WriteLine("Неверный ввод. Пожалуйста, введите число от 0 до 4.");
                }

                Console.WriteLine();
            }
        }

        static void AddStudentToGroup()
        {
            Console.WriteLine("Введите информацию о новом студенте:");
            Console.Write("Фамилия: ");
            string lastName = Console.ReadLine();
            Console.Write("Имя: ");
            string firstName = Console.ReadLine();
            Console.Write("Отчество: ");
            string middleName = Console.ReadLine();
            Console.Write("Дата рождения (гггг-мм-дд): ");
            DateTime dateOfBirth;
            if (DateTime.TryParse(Console.ReadLine(), out dateOfBirth))
            {
                Console.Write("Домашний адрес: ");
                string homeAddress = Console.ReadLine();
                Console.Write("Телефонный номер: ");
                string phoneNumber = Console.ReadLine();

                // Создать нового студента
                Student newStudent = new Student(lastName, firstName, middleName, dateOfBirth, homeAddress, phoneNumber);

                // Добавить студента в группу
                Program.group.Students.Add(newStudent);
                Console.WriteLine("Студент добавлен в группу.");
            }
            else
            {
                Console.WriteLine("Неверный формат даты рождения.");
            }
        }

        static void RemoveStudentFromGroup()
        {
            if (Program.group.Students.Count == 0)
            {
                Console.WriteLine("Группа пуста.");
                return;
            }

            Console.WriteLine("Список студентов:");
            for (int i = 0; i < Program.group.Students.Count; i++)
            {
                Console.WriteLine($"{i + 1}. {Program.group.Students[i].LastName} {Program.group.Students[i].FirstName} {Program.group.Students[i].MiddleName}");
            }

            Console.Write("Введите номер студента для удаления: ");
            int studentIndex;
            if (int.TryParse(Console.ReadLine(), out studentIndex) && studentIndex >= 1 && studentIndex <= Program.group.Students.Count)
            {
                // Удалить студента из группы
                Program.group.Students.RemoveAt(studentIndex - 1);
                Console.WriteLine("Студент удален из группы.");
            }
            else
            {
                Console.WriteLine("Неверный номер студента.");
            }
        }

        static void ShowExcellentStudents()
        {
            if (Program.group.Students.Count == 0)
            {
                Console.WriteLine("Группа пуста.");
                return;
            }

            Console.WriteLine("Отлично учатся:");
            foreach (Student student in Program.group.Students)
            {
                if (student)
                {
                    Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
                }
            }
        }

        static void ShowStudentsWithFailingGrades()
        {
            if (Program.group.Students.Count == 0)
            {
                Console.WriteLine("Группа пуста.");
                return;
            }

            Console.WriteLine("Студенты с двойками по экзаменам:");
            foreach (Student student in Program.group.Students)
            {
                if (student.Exams.Contains(2))
                {
                    Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
                }
            }
        }

        // Фильтры на анонимных методах
        static void FilterStudentsByAverageGrade(Group group)
        {
            var excellentStudents = group.FilterStudents(delegate(Student s) {
                return s.CalculateAverageGrade() >= 10;
            });
            Console.WriteLine("Студенты-отличники:");
            foreach (var student in excellentStudents)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsByName(Group group)
        {
            var studentsWithA = group.FilterStudents(delegate(Student s) {
                return s.FirstName.StartsWith("А");
            });
            Console.WriteLine("Студенты, чьи имена начинаются с буквы \"А\":");
            foreach (var student in studentsWithA)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsByFailingGrades(Group group)
        {
            var studentsWithFailingGrades = group.FilterStudents(delegate(Student s) {
                return s.Exams.Contains(2);
            });
            Console.WriteLine("Студенты с двойками по экзаменам:");
            foreach (var student in studentsWithFailingGrades)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsWithoutCredits(Group group)
        {
            var studentsWithoutCredits = group.FilterStudents(delegate(Student s) {
                return s.Credits.Count == 0;
            });
            Console.WriteLine("Студенты без оценок за ДЗ:");
            foreach (var student in studentsWithoutCredits)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        // Фильтры на лямбдах
        static void FilterStudentsByAverageGradeLambda(Group group)
        {
            var averageGrade = group.Average(s => s.CalculateAverageGrade());
            var topStudents = group.FilterStudents(s => s.CalculateAverageGrade() > averageGrade);
            Console.WriteLine("Студенты с оценкой выше среднего по группе:");
            foreach (var student in topStudents)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsByLongNameLambda(Group group)
        {
            var studentsWithLongNames = group.FilterStudents(s => s.FirstName.Length > 5);
            Console.WriteLine("Студенты с именами длиннее 5 символов:");
            foreach (var student in studentsWithLongNames)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsBySameCreditsLambda(Group group)
        {
            var studentsWithSameCredits = group.FilterStudents(s => group.Students.Any(s2 => s2 != s && s.Credits.Count == s2.Credits.Count && s.Credits.All(c => s2.Credits.Contains(c))));
            Console.WriteLine("Студенты с одинаковыми оценками за ДЗ:");
            foreach (var student in studentsWithSameCredits)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsByEvenCreditsLambda(Group group)
        {
            var studentsWithEvenCredits = group.FilterStudents(s => s.Credits.Count % 2 == 0);
            Console.WriteLine("Студенты с четным количеством оценок за ДЗ:");
            foreach (var student in studentsWithEvenCredits)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static void FilterStudentsByTotalGradesLambda(Group group)
        {
            var studentsWithHighTotalGrades = group.FilterStudents(s => (s.Credits.Sum() + s.CourseWorks.Sum() + s.Exams.Sum()) > 50);
            Console.WriteLine("Студенты, чья сумма всех оценок больше 50:");
            foreach (var student in studentsWithHighTotalGrades)
            {
                Console.WriteLine($"{student.LastName} {student.FirstName} {student.MiddleName}");
            }
        }

        static Group group;
    }
}