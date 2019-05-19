# coding=utf-8
#
# ESTRUCTURAS DE DATOS Y ALGORITMOS I
# FACULTAD DE INGENIERÍA, UNAM, 2019-1
# P R Á C T I C A   9
# INTRODUCCIÓN A PYTHON I
# Declaración de variables, funciones, estructura FOR y uso de la biblioteca matplotlib
#
# 
# Instrucciones:
# Resolver la ecuación diferencial que modela un circuito RC en serie donde
# la entrada es el voltaje de alimentación y la salida es el voltaje en el capacitor.
# La ecuación diferencial que modela el circuito es:
# d/dt(Vc) = -1/(RC)Vc + 1/(RC)V
# donde Vc es el voltaje en el capacitor y V es el voltaje de entrada.
# 
# Restricciones.
# SÓLO MODIFICAR LAS FUNCIONES INDICADAS CON LA LEYENDA 'Código por escribir'
#

import sys
import matplotlib.pyplot as plt
import numpy
import math

R  = 1.0    #Resistencia en Ohms
C  = 1.0    #Resistencia en Faradays
dt = 0.0001 #Paso de muestreo en segundos
tf = 1.0    #Tiempo final de simulación
V  = 1.0    #Voltaje de entrada (amplitud si es senoidal)
f  = 1      #Frecuencia en Hertz (si se usa este parámetro, se simulará una senoidal)

def calculate_derivate(x,u):
    #
    # Código por escribir:
    #Regresar el valor de la derivada de acuerdo con el modelo proporcionado
    #
    return -1.0/(R*C)*x + 1.0/(R*C)*u      #Regresa directamente el valor de la derivada

def solve_ode_constant():
    n  = int(tf/dt)
    t  = numpy.zeros(n)
    Vc = numpy.zeros(n)
    #
    # Código por escribir:
    # Calcular los 'n' valores de Vc resolviendo la ecuación diferencial por Runge-Kutta
    # Suponer que el voltaje de entrada es una constante 'V'
    # 
    for i in range(1,n):                    #Debemos recordar que estos ciclos estan compuestos por un conjunto, no por un limite como tal.
        t[i]= i*dt
        Vc[i]= Vc[i-1]+ dt*calculate_derivate(Vc[i-1],V)


    return t,Vc                #Regresan los valores resueltos 

def solve_ode_sinusoidal():
    n  = int(tf/dt)
    t  = numpy.zeros(n)
    Vc = numpy.zeros(n)
    n  = int(tf/dt)
    t  = numpy.zeros(n)
    Vc = numpy.zeros(n)

    for i in range(1,n):
        t[i]= i*dt
  
        Vc[i]= Vc[i-1]+ dt*calculate_derivate(Vc[i-1],V*math.sin(2*math.pi*f*t[i])) 
    #
    # Código por escribir:
    # Calcular los 'n' valores de Vc resolviendo la ecuación diferencial por Runge-Kutta
    # Suponer que el voltaje de entrada es una señal senoidal de frecuencia 'f' y amplitud 'V'
    # 
    return t,Vc

use_sinusoidal = False
if "-dt" in sys.argv:
    dt = float(sys.argv[sys.argv.index("-dt")+1])
if "-R" in sys.argv:
    R = float(sys.argv[sys.argv.index("-R")+1])
if "-C" in sys.argv:
    C = float(sys.argv[sys.argv.index("-C")+1])
if "-tf" in sys.argv:
    tf = float(sys.argv[sys.argv.index("-tf")+1])
if "-V" in sys.argv:
    V = float(sys.argv[sys.argv.index("-V")+1])
if "-f" in sys.argv:
    use_sinusoidal = True
    f = float(sys.argv[sys.argv.index("-f")+1])

if use_sinusoidal:
    t,Vc = solve_ode_sinusoidal()
else:
    t,Vc = solve_ode_constant()
plt.plot(t,Vc)
plt.show()
    


