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
		print('ingresa una contraseña que contenga de 3 a 4 caracteres')

def quicksort(lista):
	quicksort_aux(lista,0,len(lista)-1)

def quicksort_aux(lista,inicio, fin):
	if inicio < fin:

		pivote=particion(lista,inicio,fin)

		quicksort_aux(lista,inicio,pivote-1)
		quicksort_aux(lista,pivote+1,fin)

def particion(lista,inicio,fin):
	pivote=lista[inicio]
	print("Valor del pivote ",format(pivote))
	izquierda=inicio+1
	derecha=fin
	print("Indice izquierdo ",format(izquierda))
	print("Indice derecho ",format(derecha))

	bandera=False
	while not bandera:
		while izquierda <= derecha and lista[izquierda] <= pivote:
			izquierda=izquierda+1
		while lista[derecha] >= pivote and derecha >= izquierda:
			derecha=derecha-1
		if derecha < izquierda:
			bandera=True
		else:
			temp=lista[izquierda]
			lista[izquierda]=lista[derecha]
			lista[derecha]=temp

	print(lista)

	temp=lista[inicio]
	lista[inicio]=lista[derecha]
	lista[derecha]=temp
	return derecha

lista=[21, 10, 0, 11, 9, 24, 20, 14, 1]
print("Lista desordenada ",format(lista))
quicksort(lista)
print("Lista ordenada ",format(lista))


