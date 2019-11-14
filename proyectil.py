#!/usr/bin/env python
# coding: utf-8

# In[49]:


import matplotlib.pyplot as plt
import numpy as np


# In[50]:


datos = np.loadtxt('datos.dat')
datos1 = np.loadtxt('datos1.dat')


# In[51]:


posx = datos[:,0]
posy = datos[:,2]
posx1 = datos1[:,0]
posy1 = datos1[:,2]



# In[52]:


plt.figure()
plt.plot(posx,posy,label ='Con friccion')
plt.plot(posx1,posy1,label ='Sin friccion')
plt.title('Movimiento proyectil')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig('friccion.png')



# In[ ]:




