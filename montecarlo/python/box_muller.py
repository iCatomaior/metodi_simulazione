import numpy as np
import matplotlib.pyplot as plt
import math as m

gen = np.random.RandomState()
gen.seed(123456789)

N_points = 10000
n_bins  = 30

values = np.array([])

for i in range(0,N_points):
    eta_1 = gen.random()
    eta_2 = gen.random()

    x = m.sqrt(-2*m.log(eta_1))*m.cos(2*m.pi*eta_2)
    values = np.append(values,x)

plt.hist(values, n_bins)
plt.show()