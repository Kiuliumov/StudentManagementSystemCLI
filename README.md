# Student Management System (C)

A simple Student Management System written in C that allows you to:

- Add students
- View all students
- Search students by ID
- Delete students by ID

The system stores student records in a binary file and automatically
generates unique student IDs.

---

## Features

- Automatic ID generation
- Persistent storage using binary file (`students.dat`)
- Search functionality
- Delete functionality
- Simple console-based menu interface

---

## Project Structure

. ├── main.c\
├── students.dat (created automatically)\
├── id_counter.txt (created automatically)\
└── README.md

- `students.dat` stores student records in binary format.
- `id_counter.txt` keeps track of the last generated student ID.

---

## Student Structure

Each student record contains:

- `id` (int)
- `name` (char\[50\])
- `age` (int)
- `grade` (float)

---

## Compilation

```bash
gcc main.c -o student_system
```

---

## Running the Program

Linux / macOS:

```bash
./student_system
```

Windows:

```bash
student_system.exe
```

---

## Menu Options

1.  Add Student\
2.  View Students\
3.  Search Student\
4.  Delete Student\
5.  Exit

---

## How It Works

- When adding a student, the program generates a new unique ID.
- Student records are appended to `students.dat`.
- Viewing reads all records from the file.
- Searching scans the file and compares IDs.
- Deleting rewrites the file excluding the selected student.

---

## Notes

- Names cannot contain spaces (due to `scanf("%s")`).
- Data persists between program runs.
- Required files are created automatically if they do not exist.

---

## License

This project is for educational purposes.
