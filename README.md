## 🔍 Analizador Léxico

El analizador léxico del **Lenguaje NPK** trabaja directamente sobre el código fuente en crudo (pseudocódigo redactado por el usuario). Al estar diseñado como una herramienta pedagógica para programadores principiantes, el lenguaje prescinde de directivas de preprocesamiento como macros o inclusión de librerías externas; por ello, el escáner recibe el texto plano sin transformaciones previas.

Su función principal consiste en recorrer el flujo de caracteres de entrada para agruparlos y clasificarlos en **tokens**, descartando en el proceso elementos sin relevancia sintáctica como espacios en blanco, tabulaciones y saltos de línea. Si durante el recorrido encuentra un carácter o secuencia que no pertenece al alfabeto permitido, detiene la ejecución y reporta el error correspondiente.

### 📚 Vocabulario y Palabras Reservadas

Las palabras reservadas tienen prioridad de reconocimiento sobre los identificadores para evitar ambigüedades durante el escaneo. Se agrupan en las siguientes categorías:

| Categoría | Elementos |
| :--- | :--- |
| **Declaración de tipos** | `booleano`, `caracter`, `real`, `entero`, `cadena` |
| **Operadores lógicos** | `y`, `o` |
| **Operadores aritméticos** | `+`, `-`, `*`, `/`, `mod` |
| **Operadores relacionales** | `=`, `!=`, `<`, `<=`, `>`, `>=` |
| **Operador de asignación** | `:=` |
| **Estructuras de control** | `si`, `hacer`, `sino`, `sino si`, `fin si`, `repetir`, `veces`, `desde`, `hasta`, `mientras`, `fin repetir`, `fin mientras`, `salir`, `continuar` |
| **Funciones estándar** | `imprimir`, `leer` |

### 🧩 Reglas de Formación

Para mantener un control estricto y predecible sobre el léxico del lenguaje se define un alfabeto acotado compuesto por letras (`a-z`, `A-Z`), dígitos (`0-9`) y un repertorio específico de símbolos permitidos: `.`, `:`, `,`, `;`, `<`, `>`, `=`, `+`, `-`, `!`, `#`, `%`, `*`, `?`, `(`, `)`, `{`, `}`, `[`, `]`.

* **Identificadores (`ID`):** Deben comenzar obligatoriamente con una letra (mayúscula o minúscula), seguida de cero o más letras o dígitos (ej. `valorX`, `Edad1`).
* **Literales de Cadena (`CAD`) y Carácter (`CAR`):** Delimitados por comillas dobles (`" "`) y comillas simples (`' '`) respectivamente. La cadena admite combinaciones de letras, dígitos, espacios en blanco y el repertorio de símbolos mencionado anteriormente. Mientras que el carácter se limita a un solo símbolo escogido entre todos ellos, a excepción del espacio en blanco el cual no lo tiene permitido.

A continuación, se detallan las expresiones regulares que abarcan las entradas explicadas y algunas otras de interés:

| Token | Expresión Regular |
| :--- | :--- |
| `ID` | `[a-zA-Z][a-zA-Z0-9]*` |
| `CAD` | `"[a-zA-Z0-9 .:,;<>=+\-!#%*\?\(\)\{\}\[\]]*"` |
| `CAR` | `'[a-zA-Z0-9 .:,;<>=+\-!#%*\?\(\)\{\}\[\]]'` |
| `NUM_ENTERO` | `-?[0-9]+` |
| `NUM_REAL` | `-?[0-9]+(,[0-9]+)?` |

---

## ⚙️ Compilación y Ejecución

El proyecto utiliza la librería externa **DeSiGNAR**. Para facilitar la construcción y prueba del proyecto se incluyen dos scripts en la raíz del repositorio,
desde allí se deben ejecutar en el siguiente orden:

1. **`./set.sh`**: Configura el entorno mediante CMake y compila el proyecto. Si la librería *DeSiGNAR* no se encuentra instalada previamente en el sistema, CMake la descargará y compilará automáticamente desde su repositorio oficial.
```bash
./set.sh
```
2. **`./run.sh`**: Ejecuta el binario compilado.
```bash
./run.sh
```
---

## 👥 Integrantes

| Nombre y Apellido | Cédula de Identidad |
| :--- | :--- |
| María Fernanda Castillo Méndez | `29.886.792` |
| Francisco Javier Ochoa Pino | `30.189.260` |

## ⚖️ Créditos y Derechos de Autor

* **Librería DeSiGNAR:** Este proyecto hace uso de la biblioteca de estructuras de datos y algoritmos [DeSiGNAR](https://github.com/R3mmurd/DeSiGNAR), todos los derechos y créditos de dicha herramienta pertenecen a sus respectivos autores y mantenedores.

---
