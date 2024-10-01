# Blockchain
En este repositorio encontraran el codigo de los demos utilizados en la conferencia 30/09/24 para el curso de Estructura de Datos acerca de la implementacion de un blockchain basico. Todas las versiones de blockchain en este proyecto, es un blockchain que calcula un nonce que cumple con 4*n cantidad de ceros en SHA-256 resultante. Esto significa que la cantidad de ceros resultantes es en los caracteres de su representacion hexagesimal. En otras palabras, la dificultad configurada en este blockchain es 4 veces una dificultad convencional por bits. Esto por motivos visuales de la conferencia.
- blockchain-single
	- En esta carpeta se encuentra la implementacion mas simple del proyecto. La implementacion del blockchain haciendo uso de un solo hilo de programa.
- blockchain-threads
	- Esta version hace uso de la cantidad maxima de hilos que el programa detecte en el CPU de la computadora que lo esta ejecutando. Para sincronizar un resultado encontrado se utiliza un flag atomico que se usa como condicion para seguir el bucle
- blockchain-cuda
	- Esta es la version mas compleja del demo. Hace uso de la libreria CUDA para C++, que permite la ejecucion paralela de codigo en graficas NVIDIA.  Se debe ajustar el archivo utils/constants.hpp para reflejar los hilos y SMs correctos para cada tarjeta grafica.  En main.cu hay un fragmento de codigo comentado que puede ayudar a identificar estas variables. Para este proyecto en especifico (en parte se puede ver reflejado en CMakeLists.txt), se utiliza:
		- Linux (especificamente Arch)
		- Drivers Nvidia: 560.35.03
		- Cuda Toolkit/ CUDA compiler driver: 12.6(.68)

## Material Recomendado
Como mencionado en la conferencia, se sugiere fuertemente visitar el siguiente material de apoyo. Este material cubre mas a profundidad conceptos vistos en la conferencia que son fundamentales para que un Blockchain funcione de manera integra, eficiente y segura. De hecho, las animaciones utilizadas durante la presentacion de esta conferencia hacen uso de una libreria originalmente escrita por el autor de algunos de estos videos! 3Blue1Brown. Esta libreria fue luego adoptada y mantenida por la comunidad. Asegurense de mostrar su apoyo a estas grandes personas que dedican su tiempo para hacer material educativo de alta calidad.

- Pero, ¿cómo funciona realmente el bitcoin?  https://youtu.be/bBC-nXj3Ng4?si=E2YPrAbq5NzM4kh0
- ¿Qué tan segura es la seguridad de 256 bits?  https://youtu.be/S9JGmA5_unY?si=M4fvHxB4vPBMeztv
- A Definitive Guide to Learn The SHA-256 https://www.simplilearn.com/tutorials/cyber-security-tutorial/sha-256-algorithm
- C++ sha256 function http://www.zedwood.com/article/cpp-sha256-function
