#  Hospital Space Controller

Sistema de gestión hospitalaria en C++ que permite administrar la ocupación de habitaciones, el registro de pacientes, doctores y datos epidemiológicos.

---

###  Descripción General

**Hospital Space Controller** es una aplicación de consola desarrollada en C++ que simula la gestión de un hospital con múltiples pisos, cuartos y camas. Permite dar de alta y de baja a pacientes, consultar disponibilidad, buscar pacientes, generar reportes epidemiológicos y administrar información clínica, administrativa y de tratamiento.

El sistema está diseñado con un enfoque modular orientado a objetos, donde cada responsabilidad está encapsulada en clases bien definidas.

###  Características Principales

- **Gestión de habitaciones**: 3 pisos × 2 cuartos × 6 camas = 36 habitaciones.
- **Alta de pacientes**: Registro completo con datos de identificación, clínicos, tratamiento, administrativos y epidemiológicos.
- **Baja de pacientes**: Liberación de habitaciones con registro de fecha de alta.
- **Disponibilidad**: Consulta del estado de cada habitación (libre/ocupada).
- **Búsqueda de pacientes**: Localización por nombre completo con ficha detallada.
- **Reporte epidemiológico**: Identificación de pacientes con enfermedades contagiosas y casos reportados a la autoridad sanitaria.
- **Interfaz de consola**: Menú interactivo con animación de carga y limpieza de pantalla.

###  Arquitectura del Código

El proyecto se organiza en las siguientes clases:

| Clase | Responsabilidad |
|-------|-----------------|
| `DatosIdentificacion` | Información personal del paciente (nombre, edad, contacto de emergencia, etc.). |
| `DatosClinicos` | Historial médico, síntomas, diagnóstico y resultados de estudios. |
| `DatosTratamiento` | Medicamentos, cirugías, procedimientos y evolución diaria. |
| `DatosAdministrativos` | Fechas de ingreso/alta, seguro médico, costos y facturación. |
| `DatosEpidemiologicos` | Enfermedades contagiosas, aislamiento y reportes sanitarios. |
| `Doctor` | Información del médico responsable (nombre, clave, especialidad). |
| `Paciente` | Agrupa todos los datos anteriores en una entidad única. |
| `Habitacion` | Representa una cama con su paciente y doctor asignados. |
| `Hospital` | Contenedor principal que gestiona todas las habitaciones. |
| `Menu` | Interfaz de usuario y flujo principal del programa. |

Además, el namespace `Utilerias` proporciona funciones auxiliares para entrada/salida, limpieza de pantalla, formato de fecha/hora y validación de datos.


### Requisitos

- **Compilador C++11 o superior** (g++, clang++, MSVC).
- **Sistema operativo**: Windows, Linux o macOS.
- No requiere bibliotecas externas.

###  Compilación y Ejecución

**Linux / macOS:**
```bash
g++ -std=c++11 -o hospital Hospital_Space_Controller.cpp -pthread
./hospital

