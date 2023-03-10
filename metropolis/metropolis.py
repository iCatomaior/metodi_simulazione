import numpy as np
import matplotlib.pyplot as plt

#Variables
L = 8
J = 6
N_particles = int((L**2)/2)
N_acc = 0

#Functions

def Energy(matrix, L, x, y):
    return J*(matrix[(x+1+L)%L][y]+matrix[(x-1+L)%L][y]+matrix[x][(y+1+L)%L]+matrix[x][(y-1+L)%L]);

def Evolve(matrix, L, x, y):
    x_f = x; y_f = y
    
    E_i = Energy(matrix,L,x,y)
    n = np.random.random()
    
    if n<0.25:
        y_f=(y+L+1)%L

    elif n<0.5:
        y_f=(y-1+L)%L
        
    elif n<0.75:
        x_f=(x+1+L)%L
        
    else: 
        x_f=(x-1+L)%L
        
    if matrix[x_f][y_f]==0:
        E_f = Energy(matrix,L,x_f,y_f)
        p = np.exp(E_i-E_f)
        n = np.random.random()
        
        if E_f>E_i :
            if n<p :
                matrix[x][y]=0
                matrix[x_f][y_f]=1
            
        else:
            matrix[x][y]=0
            matrix[x_f][y_f]=1


# Main program

#Matrix inizialization
np.random.seed(123456789) #seed

matrix = np.zeros((L,L),int)

while (N_acc<N_particles):
    var= np.random.randint(L,size=2,dtype=int)
    if matrix[var[0]][var[1]]==0:
        matrix[var[0]][var[1]]=1
        N_acc += 1


#Evolution

NMC = 100000

for i in range(0,NMC):
    for j in range (0,N_particles):
        x = np.random.randint(L,dtype=int)
        y = np.random.randint(L,dtype=int)
        
        if matrix[x][y]==1 :
            Evolve(matrix,L,x,y)


#Plotting

plt.imshow(matrix)
plt.colorbar()
plt.show()      

