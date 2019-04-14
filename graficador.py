import numpy as np
import matplotlib.pyplot as plt



t=np.loadtxt('explicito.txt',usecols=0)
T=np.linspace(0,1,10)
Y_e=np.loadtxt('explicito.txt',usecols=1)
Y_i=np.loadtxt('implicito.txt',usecols=1)

def f(x):
    return np.exp(-4*x)
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.plot(t, Y_e, label='Numérico')
plt.scatter(T,f(T),label='Teórico')
plt.title('Euler explícito')
plt.legend()
plt.subplot(1,2,2)
plt.plot(t, Y_i, label='Numérico')
plt.scatter(T,f(T),label='Teórico')
plt.title('Implícito')
plt.legend()
plt.savefig('graficas.png')
