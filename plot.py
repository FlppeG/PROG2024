import matplotlib.pyplot as plt
import numpy as np
import sys

#Read data
data = np.genfromtxt(sys.argv[1], delimiter=',')
#data = np.loadtxt(sys.argv[1])

#Plot data
fig, axes = plt.subplots(1, 1)
axes.plot(data[:, 1], data[:, 3], '-o', color= '#ff4f00', label= "Forward")
axes.plot(data[:, 1], data[:, 5], '-s', color= '#3a405a', label= "Central") 
axes.plot(data[:, 1], data[:, 7], '-d', color= '#1effbc', label= "R forward")
axes.plot(data[:, 1], data[:, 9], '-p', color= '#99b2dd', label= "R central")
axes.set_xscale("log")
axes.set_yscale("log")
axes.set_xlabel(r"h", fontweight='bold')
axes.set_ylabel(r"Error", fontweight='bold')

axes.grid(True, color='#bebfc5', linestyle='--', linewidth=0.7)

axes.set_title(r"Error vs h, x=1.2334", fontsize = 14, fontname= 'Arial', fontweight='bold')
plt.legend()

fig.savefig("fig_python.pdf") 