#En este documento se encuentran ordenados del primero al octavo de los codigos fuente de la practica 11.

from string import ascii_letters, digits
from itertools import product

#concatenar letras y dífitos en una sola cadena
caracteres= ascii_letters+digits

def buscador (con):

	#archivo con todas las combinaciones generadas 
	archivo= open("combinaciones.txt", "w")

	if 3<= len(con)<= 4:
		for i in range (3,5):
			for comb in product(caracteres, repeat=i):
				#se utiliza join() para concatenar los caracteres regresados por la función product()
				#como join necesita una cadena inicial para hacer la concatenación, se pone una cadena vacía al principio
				prueba= "".join(comb)
				#escribiendo al archivo cada combinacion generada
				archivo.write(prueba+"\n")
				if prueba ==con:
					print ('tu contraseña es {}'. format(prueba))
					#cerrando el archivo
					archivo.close()
					break 
	else:
		print('ingresa una contraseña que contenga de 3 a 4 caracteres'

def cambio(cantidad,denominaciones):
	resultado = []
	while (cantidad > 0):
		if (cantidad >= denominaciones[0]):
			num = cantidad // denominaciones[0]
			cantidad = cantidad - (num * denominaciones[0])
			resultado.append([denominaciones[0], num])
		denominaciones = denominaciones[1:]
	return resultado

def fibonacci_bottom_up(numero):
	f_parciales=[0,1,1]
	while len(f_parciales) < numero:
		f_parciales.append(f_parciales[-1] + f_parciales[-2])
		print(f_parciales)
	return f_parciales[numero-1]
print(fibonacci_bottom_up(10))

	
#Top-down
memoria = {1:0,2:1,3:1} #Memoria inicial
import pickle #Carga la biblioteca
archivo = open('memoria.p','wb') #Se abre el archivo para escribir en modo binario
pickle.dump(memoria, archivo) #Se guarda la variable memoria que es un diccionario
archivo.close() #Se cierra el archivo
archivo = open('memoria.p','rb') #Se abre el archivo a leer en modo binario
memoria_de_archivo=pickle.load(archivo) #Se lee la variable
archivo.close() #Se cierra el archivo
def fibonacci_iterativo_v2(numero):
    f1=0
    f2=1
    for i in range (1, numero-1):
        f1,f2=f2,f1+f2 #Asignacion paralela
    return f2
def fibonacci_top_down(numero): #Si el número ya se encuentra calculado, se registra el valor ya no se hacen mas calculo
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero-1) + fibonacci_iterativo_v2(numero-2)
    memoria[numero] = f
    return memoria[numero]

print(fibonacci_iterativo_v2(12))
print (memoria_de_archivo)

def insertionSort(n_lista):
    for index in range (1,len(n_lista)):
        actual = n_lista[index]
        posicion = index
        print ("valor a ordenar = {}".format(actual))
        while posicion>0 and n_lista[posicion-1]>actual:
            n_lista[posicion] =n_lista[posicion-1]
            posicion = posicion-1
        n_lista[posicion] =actual
        print(n_lista)
        print()
    return n_lista
#Datos de entrada
lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada {}".format (lista))
insertionSort(lista)
print("lista ordenada {}".format(lista))


#%pylab inline
import matplotlib.pyplot as pyplot
from mp1_tollkits.mplot3d import Axes3D
import random
from time import time
from Practice_11_6 import insertionSort_time
from Practice_11_6 import quicksort_time
datos=[ii*100 for ii in range(1,21)]
tiempo_is=[]
tiempo_qs=[]
for ii in datos:
	lita_is=ramdon.sample(range(0,10000000), ii)
	lista_qs=lista_is.copy()
	t0=time()
	insertionSort_time(lista_is)
	tiempo_is.append(round(time()-t0,6))
	t0=time()
	quicksort_time(lista_qs)
	tiempo_qs.append(round(time()-t0,6))
print("Tiempos parciales de ejecucion en INSERT SORT { } [s]\n". format(tiempo_is))
print("Tiempos parciales de ejecucion en QUICK SORT { } [s]". format(tiempo_is))
print("Tiempos total de ejecucion en INSERT SORT { } [s]". format(sum(tiempo_is)))
print("Tiempos total de ejecucion en QUICK SORT { } [s]". format(sum(tiempo_is)))

fig, ax=subplots()
ax.plot(datos, tiempo_is, label="insert sort", maker="*", color="r")
ax.plot(datos, tiempo_qs, label="quick sort", maker="o", color="b")
ax.set_xlabel('Datos')
ax.set_ylabel('Tiempo')
ax.grid(True)
ax.lengend(loc=2);

plt.title('Tiempo de ejecucion [s] (insert vs. quick)')
plt.show()


import random
import matplotlib.pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D

times = 0
def insertionSort_graph(n_lista):
	global times
	for index in range(1, len(n_lista)):
		times += 1
		actual = n_lista[index]
		posicion = index
		while posicion>0 and n_lista[posicion-1]>actual:
			times += 1
			n_lista[posicion]=n_lista[posicion-1]
			posicion = posicion-1
		n_lista[posicion]=actual
	return n_lista
TAM = 101
eje_x = list(range(1,TAM,1))
eje_y = []
lista_variable = []

for num in eje_x:
	lista_variable = random.sample(range(0, 1000), num)
	times = 0
	lista_variable = insertionSort_graph(lista_variable)
	eje_y.append(times)

fig, ax =plt.subplots(facecolor='w', edgecolor= 'k')
ax.plot(eje_x, eje_y, marker="o", color="b", linestyle='None')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.grid(True)
ax.legend(["Insertion sort"])

plt.title('Insertion sort')
plt.show()