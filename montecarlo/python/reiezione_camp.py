import numpy as np
import matplotlib.pyplot as plt
import math as m

def gaus(x):
    return m.sqrt(2/m.pi)*m.exp(-x**2/2)

gen = np.random.RandomState()
gen.seed(123456789)

N_points = 100000
n_bins   = 40

values = np.array([])

for i in range(0, N_points):
    x = m.sqrt(2*m.e/m.pi)*gen.exponential(scale=1)
    y = x*gen.random()
    if y<gaus(x):
        if gen.random()>0.5:
            values = np.append(x,values)
        else:
            values = np.append(-x,values)

plt.hist(values,n_bins)
plt.show()