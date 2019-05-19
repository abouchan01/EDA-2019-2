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
