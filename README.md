#  Hospital Space Controller

A console-based hospital management system written in C++. It simulates the administration of a hospital with multiple floors, rooms, and beds, allowing you to admit patients, discharge them, check room availability, search records, and generate epidemiological reports.

---

##  Features

-  **Preconfigured hospital layout** — 3 floors × 2 rooms × 6 beds = **36 beds**
-  **Full patient records** — identification, clinical, treatment, administrative, and epidemiological data
-  **Doctor assignment** — each occupied bed stores the attending doctor's information
-  **Patient admission** — register a new patient into any free bed
-  **Patient discharge** — free a bed and record the discharge date automatically
-  **Room availability view** — quick overview of which beds are free or occupied
-  **Patient search** — find a patient by full name and display their complete file
-  **Totals report** — summary of every bed and its current occupant
-  **Epidemiological report** — count and list contagious cases and those reported to health authorities
-  **Cross-platform console** — clears the screen on both Windows (`CLS`) and Unix-like systems (`clear`)
-  **Loading animation** — small intro animation when the system starts

---

##  Requirements

- A C++ compiler with **C++11** or later support (e.g., `g++`, `clang++`, MSVC)
- No external libraries — standard library only

---

##  Compilation & Usage

### Linux / macOS

```bash
g++ -std=c++11 -O2 -o hospital Hospital_Space_Controller.cpp
./hospital
```

### Windows (MinGW / g++)

```bash
g++ -std=c++11 -O2 -o hospital.exe Hospital_Space_Controller.cpp
hospital.exe
```

### Windows (MSVC)

```bash
cl /EHsc /std:c++14 Hospital_Space_Controller.cpp
Hospital_Space_Controller.exe
```

>  On Windows, the code uses `system("CLS")`; on Unix-like systems it uses `system("clear")`. Both are handled automatically.

---

##  Menu Options

When you run the program, you'll see the main menu:

```
----------------------------------
Enter the option you need (1-8)
1 - Admit patient
2 - Discharge patient
3 - Availability
4 - Check discharge
5 - Search patient
6 - Print totals
7 - Epidemiological report
8 - Close system
----------------------------------
Option:
```

| Option | Description                                                     |
|--------|-----------------------------------------------------------------|
| `1`    | **Admit patient** — register a new patient in a free bed        |
| `2`    | **Discharge patient** — free a bed and record the discharge      |
| `3`    | **Availability** — list every bed as available / unavailable     |
| `4`    | **Check discharge** — verify if a patient is currently admitted  |
| `5`    | **Search patient** — display the full record of a patient        |
| `6`    | **Print totals** — summary of all beds and their occupants       |
| `7`    | **Epidemiological report** — contagious cases & reported cases   |
| `8`    | **Exit** — close the system                                      |

---

##  Project Structure

The program is organized into several classes, each representing a domain concept:

| Class                   | Responsibility                                                       |
|-------------------------|----------------------------------------------------------------------|
| `Utilities`             | Utility functions (screen clearing, input reading, dates, headers)   |
| `IdentificationData`    | Patient personal data (name, age, sex, address, emergency contact)   |
| `ClinicalData`          | Clinical data (history, symptoms, diagnosis, lab & X-ray results)    |
| `TreatmentData`         | Treatment data (medications, surgeries, procedures, daily progress)  |
| `AdministrativeData`    | Administrative data (admission/discharge dates, insurance, billing)  |
| `EpidemiologicalData`   | Epidemiological data (contagious disease, isolation, reporting)      |
| `Doctor`                | Attending doctor's information                                       |
| `Patient`               | Aggregates all patient-related data blocks                           |
| `Room`                  | A single bed with its patient and doctor                             |
| `Hospital`              | Collection of beds plus all operations                               |
| `Menu`                  | Console UI and main loop                                             |

---

##  Hospital Layout

- **Floors:** 3
- **Rooms per floor:** 2
- **Beds per room:** 6
- **Total beds:** 36

Each bed is uniquely numbered and displayed with a status marker:

```
[F] = free      [O] = occupied
```

Example diagram:

```
 0[F]  1[F]  2[O]  3[F]
 4[F]  5[F]  6[F]  7[O]
 ...
floor: 1
----
```

---

##  Data Handling Notes

- All data lives **in memory only** — nothing is persisted between runs.
- Discharging a patient clears all of their stored records and frees the bed.
- Input is validated for integers and decimals to avoid crashes on bad input.
- Dates are captured as strings, with the current date used automatically for admissions and discharges.

---

##  How It Works

1. **Startup** — a welcome header, a pause, and a short loading animation.
2. **Menu loop** — the user selects an option; the screen is cleared between actions.
3. **Admission** — the user picks a free bed and enters the full patient and doctor data.
4. **Discharge** — the user picks an occupied bed; the discharge date is set and the bed is cleared.
5. **Search / Reports** — iterate over all beds and filter by the requested criteria.
6. **Exit** — option `8` closes the loop and ends the program.

---
