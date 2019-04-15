import numpy as np
import matplotlib.pyplot as plt



t=np.loadtxt('explicito.txt',usecols=0)
T=np.linspace(0,40,1000)
Y_e=np.loadtxt('explicito.txt',usecols=1)
Y_r=np.loadtxt('rk4.txt',usecols=1)

def f(x):
    return 0.5*np.cos(x)

plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.plot(t, Y_e, label='Numérico')
plt.plot(T,f(T),label='Teórico')
plt.title('Euler explícito')
plt.legend()
plt.subplot(1,2,2)
t=np.loadtxt('rk4.txt',usecols=0)
plt.plot(t, Y_r, label='Numérico')
plt.plot(T,f(T),label='Teórico')
plt.title('Runge-Kutta')
plt.legend()
plt.savefig('graficas.png')
