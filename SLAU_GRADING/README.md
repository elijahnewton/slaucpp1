# SLAU Grading System

A Windows Forms (C++/CLI) desktop application that records student course marks,
computes letter grades, GPA, CGPA and pass/fail status, and stores everything in a
MySQL database.

## Features

- Enter a student's **registration number** and **full name**
- Enter any number of **course units** with a code, name and percentage mark
- Automatic **letter grade** (A, B+, B, B-, C+, C, C-, D, F) and **grade points**
- Automatic **GPA** and **CGPA** (single semester) on a **5.0 scale**
- **Pass / Fail** result (any mark below 50% is a fail)
- **Save** records to MySQL and **retrieve** them in the same app
- Modern, custom-styled user interface
- Database connection string entered **at runtime** (first-run setup or *DB Settings*)

---

## Grading Scale

| Percentage | Grade | Grade Points |
|------------|-------|--------------|
| 90 - 100   | A     | 5.0          |
| 85 - 89    | B+    | 4.5          |
| 80 - 84    | B     | 4.0          |
| 75 - 79    | B-    | 3.5          |
| 70 - 74    | C+    | 3.0          |
| 65 - 69    | C     | 2.5          |
| 60 - 64    | C-    | 2.0          |
| 50 - 59    | D     | 1.0          |
| 0 - 49     | F     | 0.0          |

- **Pass mark:** 50%
- **GPA / CGPA:** average of grade points (equal weighting per course, 5.0 max)
- **Status:** `FAIL` if any course mark is below 50%, otherwise `PASS`

---

## Configuration

### 1. Database connection string

The connection string is entered **at runtime**, so it is never hard-coded.

- On **first launch**, the *Database Connection Settings* dialog opens automatically.
- You can reopen it any time with the **DB Settings** button on the main window.

Format:

```
Server=<host>;Port=3306;Database=slau_grading;Uid=<user>;Pwd=<password>;
```

Example:

```
Server=localhost;Port=3306;Database=slau_grading;Uid=root;Pwd=yourpassword;
```

Use **Test Connection** to verify before saving. The string is stored in a
`db.config` file next to the executable.

### 2. Database / schema

The application creates its tables automatically the first time a valid
connection is saved (`CREATE TABLE IF NOT EXISTS ...`). You only need an empty
MySQL database named e.g. `slau_grading`.

Tables:

- `students` - registration number, full name
- `courses` - course code/name, mark, letter grade, grade points
- `results` - GPA, CGPA, status, course count, timestamp

### 3. Requirements

- Windows 10/11
- Visual Studio 2022 (or later) with the **Desktop development with C++** workload
  and **C++/CLI support for v143 build tools** (or the installed v145 toolset)
- .NET Framework 4.7.2 targeting pack
- MySQL Server (or any MySQL-compatible server) reachable from the machine

---

## Building

1. Open `SLAU_GRADING.slnx` (or `SLAU_GRADING.sln`) in Visual Studio.
2. Select the **x64** configuration.
3. Build (**Ctrl+Shift+B**).

The MySQL connector (`MySql.Data.dll`) is included in the `lib` folder and is
copied to the output automatically.

### Editing forms visually

The forms (`MyForm.h`, `SettingsForm.h`, `ResultsForm.h`, `RecordsForm.h`) use the
standard **Windows Form Designer** pattern: each form has an
`InitializeComponent()` method and its controls are declared as class members.

To edit a form visually:

1. Build the solution once so the project is healthy.
2. In **Solution Explorer**, right-click a form (e.g. `MyForm.h`).
3. Choose **View Designer**.

> Note: the visual designer for C++/CLI is the .NET Framework (in-process) designer.
> Keep `InitializeComponent()` intact — Visual Studio regenerates it when you edit
> the form visually. Put your logic in separate methods, not inside
> `InitializeComponent()`.

---

## Project layout

```
SLAU_GRADING/
├── MyForm.h / .cpp        Main window + application entry point
├── SettingsForm.h         Database connection-string dialog
├── ResultsForm.h          Read-only result slip
├── RecordsForm.h          List of saved student records
├── Core/
│   └── GradingEngine.h    Grade / GPA / pass-fail calculations
├── Data/
│   └── DatabaseHelper.h   MySQL connection + CRUD
├── Models/                Student, Course, Result value types
├── UI/
│   └── ModernTheme.h      Colours, fonts and control styling
├── lib/
│   └── MySql.Data.dll     MySQL .NET connector
└── README.md
```

---

## Usage

1. Start the app and enter the MySQL connection string, then **Save & Connect**.
2. Enter the student's registration number and full name.
3. Add course units and their percentage marks; grades and points update live.
4. Press **Calculate & Save** to compute and store the result.
5. Press **View Records** to browse saved students, then double-click one to open
   its result slip.
