#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>
#include <limits>
#include <ctime>

using namespace std;

// ============================================================
// UTILIDADES GENERALES
// ============================================================
namespace Utilerias {

    inline void limpiarPantalla() {
#ifdef _WIN32
        system("CLS");
#else
        system("clear");
#endif
    }

    inline void pausar() {
        cout << "\nPresiona ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    inline string leerLinea(const string& mensaje) {
        string valor;
        cout << mensaje;
        getline(cin, valor);
        return valor;
    }

    inline double leerDecimal(const string& mensaje) {
        double valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">>> Valor invalido, intenta de nuevo.\n";
        }
    }

    inline int leerEntero(const string& mensaje) {
        int valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">>> Valor invalido, intenta de nuevo.\n";
        }
    }

    inline string fechaActual() {
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", tiempoLocal);
        return string(buffer);
    }

    inline string horaActual() {
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        char buffer[6];
        strftime(buffer, sizeof(buffer), "%H:%M", tiempoLocal);
        return string(buffer);
    }

    inline void mostrarEncabezado(const string& titulo) {
        cout << "==================================================\n";
        cout << "  " << titulo << "\n";
        cout << "==================================================\n";
    }

    inline void mostrarSubencabezado(const string& titulo) {
        cout << "--- " << titulo << " ---\n";
    }
}

using namespace Utilerias;

// ============================================================
// CLASE: DatosIdentificacion
// ============================================================
class DatosIdentificacion {
private:
    string nombreCompleto;
    int    edad;
    string sexo;
    string direccion;
    string telefono;
    string contactoEmergenciaNombre;
    string contactoEmergenciaTelefono;

public:
    DatosIdentificacion() { limpiar(); }

    void limpiar() {
        nombreCompleto = "N/A";
        edad = 0;
        sexo = "N/A";
        direccion = " ";
        telefono = " ";
        contactoEmergenciaNombre = " ";
        contactoEmergenciaTelefono = " ";
    }

    bool estaVacio() const { return nombreCompleto == "N/A"; }

    // Getters
    const string& getNombreCompleto()               const { return nombreCompleto; }
    int           getEdad()                         const { return edad; }
    const string& getSexo()                         const { return sexo; }
    const string& getDireccion()                    const { return direccion; }
    const string& getTelefono()                     const { return telefono; }
    const string& getContactoEmergenciaNombre()     const { return contactoEmergenciaNombre; }
    const string& getContactoEmergenciaTelefono()   const { return contactoEmergenciaTelefono; }

    // Setters
    void setNombreCompleto(const string& valor)             { nombreCompleto = valor; }
    void setEdad(int valor)                                 { edad = valor; }
    void setSexo(const string& valor)                       { sexo = valor; }
    void setDireccion(const string& valor)                  { direccion = valor; }
    void setTelefono(const string& valor)                   { telefono = valor; }
    void setContactoEmergenciaNombre(const string& valor)   { contactoEmergenciaNombre = valor; }
    void setContactoEmergenciaTelefono(const string& valor) { contactoEmergenciaTelefono = valor; }

    void capturar() {
        mostrarSubencabezado("Datos de identificacion");
        nombreCompleto = leerLinea("Nombre completo: ");
        edad = leerEntero("Edad: ");
        sexo = leerLinea("Sexo: ");
        direccion = leerLinea("Direccion: ");
        telefono = leerLinea("Telefono: ");
        contactoEmergenciaNombre = leerLinea("Contacto de emergencia (nombre): ");
        contactoEmergenciaTelefono = leerLinea("Contacto de emergencia (telefono): ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos de identificacion");
        cout << "Nombre completo: " << nombreCompleto << "\n";
        cout << "Edad: " << edad << " | Sexo: " << sexo << "\n";
        cout << "Direccion: " << direccion << "\n";
        cout << "Telefono: " << telefono << "\n";
        cout << "Contacto de emergencia: " << contactoEmergenciaNombre
             << " (" << contactoEmergenciaTelefono << ")\n";
    }
};

// ============================================================
// CLASE: DatosClinicos
// ============================================================
class DatosClinicos {
private:
    string historialEnfermedades;
    string sintomasActuales;
    string diagnostico;
    string resultadosLaboratorio;
    string resultadosRadiografias;

public:
    DatosClinicos() { limpiar(); }

    void limpiar() {
        historialEnfermedades = " ";
        sintomasActuales = " ";
        diagnostico = " ";
        resultadosLaboratorio = " ";
        resultadosRadiografias = " ";
    }

    const string& getHistorialEnfermedades() const { return historialEnfermedades; }
    const string& getSintomasActuales()      const { return sintomasActuales; }
    const string& getDiagnostico()           const { return diagnostico; }
    const string& getResultadosLaboratorio() const { return resultadosLaboratorio; }
    const string& getResultadosRadiografias()const { return resultadosRadiografias; }

    void setHistorialEnfermedades(const string& valor) { historialEnfermedades = valor; }
    void setSintomasActuales(const string& valor)      { sintomasActuales = valor; }
    void setDiagnostico(const string& valor)           { diagnostico = valor; }
    void setResultadosLaboratorio(const string& valor) { resultadosLaboratorio = valor; }
    void setResultadosRadiografias(const string& valor){ resultadosRadiografias = valor; }

    void capturar() {
        mostrarSubencabezado("Datos clinicos y medicos");
        historialEnfermedades = leerLinea("Historial de enfermedades: ");
        sintomasActuales      = leerLinea("Sintomas actuales: ");
        diagnostico           = leerLinea("Diagnostico: ");
        resultadosLaboratorio = leerLinea("Resultados de laboratorio: ");
        resultadosRadiografias= leerLinea("Resultados de radiografias: ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos clinicos y medicos");
        cout << "Historial de enfermedades: " << historialEnfermedades << "\n";
        cout << "Sintomas actuales: " << sintomasActuales << "\n";
        cout << "Diagnostico: " << diagnostico << "\n";
        cout << "Resultados de laboratorio: " << resultadosLaboratorio << "\n";
        cout << "Resultados de radiografias: " << resultadosRadiografias << "\n";
    }
};

// ============================================================
// CLASE: DatosTratamiento
// ============================================================
class DatosTratamiento {
private:
    string medicamentosRecetados;
    string cirugiasRealizadas;
    string procedimientosMedicos;
    string evolucionDiaria;

public:
    DatosTratamiento() { limpiar(); }

    void limpiar() {
        medicamentosRecetados = " ";
        cirugiasRealizadas = " ";
        procedimientosMedicos = " ";
        evolucionDiaria = " ";
    }

    const string& getMedicamentosRecetados() const { return medicamentosRecetados; }
    const string& getCirugiasRealizadas()    const { return cirugiasRealizadas; }
    const string& getProcedimientosMedicos() const { return procedimientosMedicos; }
    const string& getEvolucionDiaria()       const { return evolucionDiaria; }

    void setMedicamentosRecetados(const string& valor) { medicamentosRecetados = valor; }
    void setCirugiasRealizadas(const string& valor)    { cirugiasRealizadas = valor; }
    void setProcedimientosMedicos(const string& valor) { procedimientosMedicos = valor; }
    void setEvolucionDiaria(const string& valor)       { evolucionDiaria = valor; }

    void capturar() {
        mostrarSubencabezado("Datos de tratamientos");
        medicamentosRecetados = leerLinea("Medicamentos recetados: ");
        cirugiasRealizadas    = leerLinea("Cirugias realizadas: ");
        procedimientosMedicos = leerLinea("Procedimientos medicos: ");
        evolucionDiaria       = leerLinea("Evolucion diaria: ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos de tratamientos");
        cout << "Medicamentos recetados: " << medicamentosRecetados << "\n";
        cout << "Cirugias realizadas: " << cirugiasRealizadas << "\n";
        cout << "Procedimientos medicos: " << procedimientosMedicos << "\n";
        cout << "Evolucion diaria: " << evolucionDiaria << "\n";
    }
};

// ============================================================
// CLASE: DatosAdministrativos
// ============================================================
class DatosAdministrativos {
private:
    string fechaIngreso;
    string fechaAlta;
    string tipoSeguroMedico;
    double costoTotalServicios;
    string datosFacturacion;

public:
    DatosAdministrativos() { limpiar(); }

    void limpiar() {
        fechaIngreso = " ";
        fechaAlta = " ";
        tipoSeguroMedico = " ";
        costoTotalServicios = 0.0;
        datosFacturacion = " ";
    }

    const string& getFechaIngreso()      const { return fechaIngreso; }
    const string& getFechaAlta()         const { return fechaAlta; }
    const string& getTipoSeguroMedico()  const { return tipoSeguroMedico; }
    double        getCostoTotalServicios() const { return costoTotalServicios; }
    const string& getDatosFacturacion()  const { return datosFacturacion; }

    void setFechaIngreso(const string& valor)      { fechaIngreso = valor; }
    void setFechaAlta(const string& valor)         { fechaAlta = valor; }
    void setTipoSeguroMedico(const string& valor)  { tipoSeguroMedico = valor; }
    void setCostoTotalServicios(double valor)      { costoTotalServicios = valor; }
    void setDatosFacturacion(const string& valor)  { datosFacturacion = valor; }

    void capturarIngreso() {
        mostrarSubencabezado("Datos administrativos");
        fechaIngreso      = leerLinea("Fecha de ingreso (dd/mm/aaaa): ");
        tipoSeguroMedico  = leerLinea("Tipo de seguro medico: ");
        costoTotalServicios = leerDecimal("Costo total de servicios: ");
        datosFacturacion  = leerLinea("Datos de facturacion: ");
        fechaAlta         = "Pendiente";
    }

    void capturar() {
        capturarIngreso();
        fechaAlta = leerLinea("Fecha de alta (dd/mm/aaaa): ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos administrativos");
        cout << "Fecha de ingreso: " << fechaIngreso << "\n";
        cout << "Fecha de alta: " << fechaAlta << "\n";
        cout << "Tipo de seguro medico: " << tipoSeguroMedico << "\n";
        cout << "Costo total de servicios: $" << fixed << setprecision(2)
             << costoTotalServicios << "\n";
        cout << "Datos de facturacion: " << datosFacturacion << "\n";
    }
};

// ============================================================
// CLASE: DatosEpidemiologicos
// ============================================================
class DatosEpidemiologicos {
private:
    bool   enfermedadContagiosa;
    string nombreEnfermedadContagiosa;
    string medidasAislamiento;
    bool   reportadoAutoridadSanitaria;
    string observacionesEpidemiologicas;

public:
    DatosEpidemiologicos() { limpiar(); }

    void limpiar() {
        enfermedadContagiosa = false;
        nombreEnfermedadContagiosa = " ";
        medidasAislamiento = " ";
        reportadoAutoridadSanitaria = false;
        observacionesEpidemiologicas = " ";
    }

    bool   tieneEnfermedadContagiosa()   const { return enfermedadContagiosa; }
    const string& getNombreEnfermedadContagiosa() const { return nombreEnfermedadContagiosa; }
    const string& getMedidasAislamiento() const { return medidasAislamiento; }
    bool   fueReportadoAutoridadSanitaria() const { return reportadoAutoridadSanitaria; }
    const string& getObservacionesEpidemiologicas() const { return observacionesEpidemiologicas; }

    void setEnfermedadContagiosa(bool valor)             { enfermedadContagiosa = valor; }
    void setNombreEnfermedadContagiosa(const string& v)  { nombreEnfermedadContagiosa = v; }
    void setMedidasAislamiento(const string& v)          { medidasAislamiento = v; }
    void setReportadoAutoridadSanitaria(bool valor)      { reportadoAutoridadSanitaria = valor; }
    void setObservacionesEpidemiologicas(const string& v){ observacionesEpidemiologicas = v; }

    void capturar() {
        mostrarSubencabezado("Datos epidemiologicos");
        int opcion = leerEntero("¿El paciente tiene enfermedad contagiosa? (1=Si, 0=No): ");
        enfermedadContagiosa = (opcion == 1);
        if (enfermedadContagiosa) {
            nombreEnfermedadContagiosa = leerLinea("Nombre de la enfermedad contagiosa: ");
            medidasAislamiento         = leerLinea("Medidas de aislamiento: ");
        }
        int reportado = leerEntero("¿Se reporto a la autoridad sanitaria? (1=Si, 0=No): ");
        reportadoAutoridadSanitaria = (reportado == 1);
        observacionesEpidemiologicas = leerLinea("Observaciones epidemiologicas: ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos epidemiologicos");
        cout << "Enfermedad contagiosa: " << (enfermedadContagiosa ? "Si" : "No") << "\n";
        if (enfermedadContagiosa) {
            cout << "Nombre: " << nombreEnfermedadContagiosa << "\n";
            cout << "Medidas de aislamiento: " << medidasAislamiento << "\n";
        }
        cout << "Reportado a autoridad sanitaria: "
             << (reportadoAutoridadSanitaria ? "Si" : "No") << "\n";
        cout << "Observaciones: " << observacionesEpidemiologicas << "\n";
    }
};

// ============================================================
// CLASE: Doctor
// ============================================================
class Doctor {
private:
    string nombreCompleto;
    string clave;
    string telefono;
    string especialidad;

public:
    Doctor() { limpiar(); }

    void limpiar() {
        nombreCompleto = " ";
        clave = " ";
        telefono = " ";
        especialidad = " ";
    }

    const string& getNombreCompleto() const { return nombreCompleto; }
    const string& getClave()          const { return clave; }
    const string& getTelefono()       const { return telefono; }
    const string& getEspecialidad()   const { return especialidad; }

    void setNombreCompleto(const string& v) { nombreCompleto = v; }
    void setClave(const string& v)          { clave = v; }
    void setTelefono(const string& v)       { telefono = v; }
    void setEspecialidad(const string& v)   { especialidad = v; }

    void capturar() {
        mostrarSubencabezado("Datos del doctor");
        nombreCompleto = leerLinea("Nombre completo: ");
        clave          = leerLinea("Clave: ");
        telefono       = leerLinea("Telefono: ");
        especialidad   = leerLinea("Especialidad: ");
    }

    void mostrar() const {
        mostrarSubencabezado("Datos del doctor");
        cout << "Nombre completo: " << nombreCompleto << "\n";
        cout << "Clave: " << clave << " | Especialidad: " << especialidad << "\n";
        cout << "Telefono: " << telefono << "\n";
    }
};

// ============================================================
// CLASE: Paciente
// ============================================================
class Paciente {
private:
    DatosIdentificacion  identificacion;
    DatosClinicos        clinicos;
    DatosTratamiento     tratamiento;
    DatosAdministrativos administrativos;
    DatosEpidemiologicos epidemiologicos;

public:
    Paciente() {}

    bool estaVacio() const { return identificacion.estaVacio(); }

    void limpiar() {
        identificacion.limpiar();
        clinicos.limpiar();
        tratamiento.limpiar();
        administrativos.limpiar();
        epidemiologicos.limpiar();
    }

    // Referencias no constantes para captura
    DatosIdentificacion&  getIdentificacion()  { return identificacion; }
    DatosClinicos&        getClinicos()        { return clinicos; }
    DatosTratamiento&     getTratamiento()     { return tratamiento; }
    DatosAdministrativos& getAdministrativos() { return administrativos; }
    DatosEpidemiologicos& getEpidemiologicos() { return epidemiologicos; }

    // Versiones constantes para consulta
    const DatosIdentificacion&  getIdentificacion()  const { return identificacion; }
    const DatosClinicos&        getClinicos()        const { return clinicos; }
    const DatosTratamiento&     getTratamiento()     const { return tratamiento; }
    const DatosAdministrativos& getAdministrativos() const { return administrativos; }
    const DatosEpidemiologicos& getEpidemiologicos() const { return epidemiologicos; }

    const string& getNombreCompleto() const { return identificacion.getNombreCompleto(); }

    void capturar() {
        identificacion.capturar();
        clinicos.capturar();
        tratamiento.capturar();
        administrativos.capturarIngreso();
        epidemiologicos.capturar();
    }

    void mostrarCompleto() const {
        identificacion.mostrar();
        clinicos.mostrar();
        tratamiento.mostrar();
        administrativos.mostrar();
        epidemiologicos.mostrar();
    }
};

// ============================================================
// CLASE: Habitacion
// ============================================================
class Habitacion {
private:
    int numero;
    int piso;
    int cuarto;
    int cama;
    Paciente paciente;
    Doctor   doctor;

public:
    Habitacion(int numeroHabitacion, int pisoHabitacion, int cuartoHabitacion, int camaHabitacion)
        : numero(numeroHabitacion), piso(pisoHabitacion),
          cuarto(cuartoHabitacion), cama(camaHabitacion) {}

    int getNumero() const { return numero; }
    int getPiso()   const { return piso; }
    int getCuarto() const { return cuarto; }
    int getCama()   const { return cama; }

    Paciente& getPaciente() { return paciente; }
    Doctor&   getDoctor()   { return doctor; }

    const Paciente& getPaciente() const { return paciente; }
    const Doctor&   getDoctor()   const { return doctor; }

    bool estaLibre() const { return paciente.estaVacio(); }

    void darBaja() {
        paciente.getAdministrativos().setFechaAlta(fechaActual());
        paciente.limpiar();
        doctor.limpiar();
    }

    void mostrarResumen() const {
        cout << "----------------------------------\n";
        cout << "Habitacion: " << numero
             << " | Piso: " << piso
             << " | Cuarto: " << cuarto
             << " | Cama: " << cama << "\n";
        if (estaLibre()) {
            cout << "Estado: LIBRE\n";
        } else {
            cout << "Paciente: " << paciente.getIdentificacion().getNombreCompleto() << "\n";
            cout << "Edad: " << paciente.getIdentificacion().getEdad()
                 << " | Sexo: " << paciente.getIdentificacion().getSexo() << "\n";
            cout << "Diagnostico: " << paciente.getClinicos().getDiagnostico() << "\n";
            cout << "Fecha de ingreso: "
                 << paciente.getAdministrativos().getFechaIngreso() << "\n";
        }
        cout << "----------------------------------\n";
    }
};

// ============================================================
// CLASE: Hospital
// ============================================================
class Hospital {
private:
    vector<Habitacion> habitaciones;
    static const int PISOS   = 3;
    static const int CUARTOS = 2;
    static const int CAMAS   = 6;

public:
    Hospital() {
        int numeroHabitacion = 0;
        for (int piso = 1; piso <= PISOS; ++piso)
            for (int cuarto = 1; cuarto <= CUARTOS; ++cuarto)
                for (int cama = 1; cama <= CAMAS; ++cama)
                    habitaciones.emplace_back(numeroHabitacion++, piso, cuarto, cama);
    }

    int totalHabitaciones() const { return static_cast<int>(habitaciones.size()); }

    void mostrarDiagrama() const {
        mostrarEncabezado("Diagrama del hospital");
        cout << "[L]=libre  [O]=ocupado\n\n";

        int contadorHabitaciones = 0;
        int pisoActual = 1;
        for (const auto& habitacion : habitaciones) {
            cout << setw(2) << habitacion.getNumero()
                 << "[" << (habitacion.estaLibre() ? "L" : "O") << "] ";

            if (++contadorHabitaciones % 4 == 0) cout << "\n";

            if (contadorHabitaciones % 12 == 0) {
                cout << "piso: " << pisoActual++ << "\n----\n";
            }
        }
        cout << "----------------------------------\n";
    }

    // --------------------------------------------------------
    // ALTA DE PACIENTE
    // --------------------------------------------------------
    void darAltaPaciente() {
        mostrarDiagrama();

        int numeroHabitacion = pedirHabitacion("Ingresa la habitacion para dar de alta: ");
        if (numeroHabitacion < 0) return;

        if (!habitaciones[numeroHabitacion].estaLibre()) {
            cout << ">>> Esta habitacion esta ocupada.\n";
            return;
        }

        mostrarEncabezado("Registro de nuevo paciente");

        Paciente& paciente = habitaciones[numeroHabitacion].getPaciente();
        Doctor&   doctor   = habitaciones[numeroHabitacion].getDoctor();

        paciente.capturar();
        doctor.capturar();

        paciente.getAdministrativos().setFechaIngreso(fechaActual());
        paciente.getAdministrativos().setFechaAlta("Pendiente");

        cout << ">>> Paciente registrado correctamente en la habitacion "
             << numeroHabitacion << ".\n";
    }

    // --------------------------------------------------------
    // BAJA DE PACIENTE
    // --------------------------------------------------------
    void darBajaPaciente() {
        mostrarDiagrama();

        int numeroHabitacion = pedirHabitacion("Ingresa la habitacion para dar de baja: ");
        if (numeroHabitacion < 0) return;

        if (habitaciones[numeroHabitacion].estaLibre()) {
            cout << ">>> Esa habitacion ya esta libre.\n";
            return;
        }

        habitaciones[numeroHabitacion].darBaja();
        cout << ">>> Paciente dado de baja de la habitacion "
             << numeroHabitacion << ".\n";
    }

    // --------------------------------------------------------
    // DISPONIBILIDAD
    // --------------------------------------------------------
    void mostrarDisponibilidad() const {
        mostrarEncabezado("Disponibilidad de habitaciones");
        for (const auto& habitacion : habitaciones) {
            cout << "Habitacion " << setw(2) << habitacion.getNumero()
                 << (habitacion.estaLibre() ? " Disponible" : " No disponible") << "\n";
        }
    }

    // --------------------------------------------------------
    // REVISAR ALTA
    // --------------------------------------------------------
    void revisarAltaPaciente() const {
        string nombreBuscado = leerLinea("Nombre completo del paciente a revisar: ");

        bool encontrado = false;
        for (const auto& habitacion : habitaciones) {
            if (!habitacion.estaLibre() &&
                habitacion.getPaciente().getNombreCompleto() == nombreBuscado) {
                cout << ">>> Paciente encontrado en la habitacion "
                     << habitacion.getNumero() << ".\n";
                encontrado = true;
            }
        }
        if (!encontrado)
            cout << ">>> Paciente no encontrado.\n";
    }

    // --------------------------------------------------------
    // BUSCAR PACIENTE
    // --------------------------------------------------------
    void buscarPaciente() const {
        string nombreBuscado = leerLinea("Nombre completo del paciente a buscar: ");

        bool encontrado = false;
        for (const auto& habitacion : habitaciones) {
            if (!habitacion.estaLibre() &&
                habitacion.getPaciente().getNombreCompleto() == nombreBuscado) {

                encontrado = true;

                mostrarEncabezado("Ficha del paciente");
                cout << "Habitacion: " << habitacion.getNumero()
                     << " | Piso: " << habitacion.getPiso()
                     << " | Cuarto: " << habitacion.getCuarto()
                     << " | Cama: " << habitacion.getCama() << "\n\n";

                habitacion.getPaciente().mostrarCompleto();
                habitacion.getDoctor().mostrar();
            }
        }
        if (!encontrado)
            cout << ">>> Paciente no encontrado.\n";
    }

    // --------------------------------------------------------
    // IMPRIMIR TOTALES
    // --------------------------------------------------------
    void imprimirTotales() const {
        for (const auto& habitacion : habitaciones)
            habitacion.mostrarResumen();
    }

    // --------------------------------------------------------
    // REPORTE EPIDEMIOLOGICO
    // --------------------------------------------------------
    void reporteEpidemiologico() const {
        mostrarEncabezado("Reporte epidemiologico");

        int contagiosos = 0;
        int reportados = 0;

        for (const auto& habitacion : habitaciones) {
            if (habitacion.estaLibre()) continue;

            const DatosEpidemiologicos& epidemiologia =
                habitacion.getPaciente().getEpidemiologicos();

            if (epidemiologia.tieneEnfermedadContagiosa()) {
                ++contagiosos;
                cout << "Habitacion " << habitacion.getNumero()
                     << " | Paciente: "
                     << habitacion.getPaciente().getNombreCompleto()
                     << " | Enfermedad: "
                     << epidemiologia.getNombreEnfermedadContagiosa()
                     << " | Reportado: "
                     << (epidemiologia.fueReportadoAutoridadSanitaria() ? "Si" : "No")
                     << "\n";
            }
            if (epidemiologia.fueReportadoAutoridadSanitaria()) ++reportados;
        }

        cout << "\nTotal de pacientes con enfermedad contagiosa: "
             << contagiosos << "\n";
        cout << "Total de casos reportados a la autoridad sanitaria: "
             << reportados << "\n";
    }

private:
    int pedirHabitacion(const string& mensaje) const {
        int numeroHabitacion = leerEntero(mensaje);
        if (numeroHabitacion < 0 || numeroHabitacion >= totalHabitaciones()) {
            cout << ">>> Habitacion invalida.\n";
            return -1;
        }
        return numeroHabitacion;
    }
};

// ============================================================
// CLASE: Menu
// ============================================================
class Menu {
private:
    Hospital hospital;

    void mostrarOpciones() const {
        cout << "----------------------------------\n";
        cout << "Introduce la opcion que requieras (1-8)\n";
        cout << "1 - Dar alta\n";
        cout << "2 - Dar baja\n";
        cout << "3 - Disponibilidad\n";
        cout << "4 - Revisar alta\n";
        cout << "5 - Buscar paciente\n";
        cout << "6 - Imprimir totales\n";
        cout << "7 - Reporte epidemiologico\n";
        cout << "8 - Cerrar sistema\n";
        cout << "----------------------------------\n";
        cout << "Opcion: ";
    }

    void animacionCarga() {
        for (int porcentaje = 1; porcentaje <= 100; porcentaje += 9) {
            limpiarPantalla();
            cout << "Cargando..." << porcentaje << "%";
            this_thread::sleep_for(chrono::milliseconds(120));
        }
        limpiarPantalla();
    }

public:
    void ejecutar() {
        mostrarEncabezado("Bienvenido al sistema del hospital");
        pausar();
        animacionCarga();

        int opcion = 0;
        do {
            mostrarOpciones();
            opcion = leerEntero("");
            limpiarPantalla();

            switch (opcion) {
                case 1: hospital.darAltaPaciente();       break;
                case 2: hospital.darBajaPaciente();       break;
                case 3: hospital.mostrarDisponibilidad(); break;
                case 4: hospital.revisarAltaPaciente();   break;
                case 5: hospital.buscarPaciente();        break;
                case 6: hospital.imprimirTotales();       break;
                case 7: hospital.reporteEpidemiologico(); break;
                case 8: cout << "Cerrando sesion...\n";   break;
                default: cout << ">>> Opcion invalida.\n";
            }

            if (opcion != 8) pausar();
            limpiarPantalla();

        } while (opcion != 8);
    }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    Menu menu;
    menu.ejecutar();
    return 0;
}