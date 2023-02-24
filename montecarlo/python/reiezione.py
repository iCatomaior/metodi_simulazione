import numpy as np
import math as m
import matplotlib.pyplot as plt

gen = np.random.RandomState()
gen.seed(123456789)

N_points = 100000
n_bins  = 40

nacc=0
values = np.array([])

for i in range (0,N_points):
    x = 2*m.pi*gen.random()
    y = gen.random()
    if y<abs(m.cos(x)):
        nacc += 1
        values = np.append(x, values)

plt.hist(values,n_bins)
plt.show()