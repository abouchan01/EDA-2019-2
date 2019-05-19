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
