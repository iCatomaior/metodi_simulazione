import numpy as np
import math as m
import matplotlib.pyplot as plt


gen = np.random.RandomState()
gen.seed(123456789)

#setting variables
N_points = 10000
n_bins   = 20
alpha    = 3

#saving array
values = np.array([])

for i in range(0,N_points):
    eta=gen.random()
    x= -(1/alpha)*m.log(eta)
    values = np.append(values, x)

plt.hist(values, n_bins)
plt.show()
