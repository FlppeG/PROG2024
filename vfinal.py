import matplotlib.pyplot as plt
import numpy as np
import sys

#Read data
#data = np.genfromtxt(sys.argv[1], delimiter=' ')
data = np.loadtxt(sys.argv[1])

#Plot data
fig, axes = plt.subplots(1, 1)
axes.plot(data[:, 0], data[:, 1], '-o', color= '#ff4f00', label= "V final", markersize=3)

axes.set_xscale("log")
axes.set_yscale("log")
axes.set_xlabel(r"x", fontweight='bold')
axes.set_ylabel(r"v final", fontweight='bold')

axes.grid(True, color='#bebfc5', linestyle='--', linewidth=0.7)

axes.set_title(r"posición vs velocidad final", fontsize = 14, fontname= 'Arial', fontweight='bold')
plt.legend()

fig.savefig("xvsvfinallog.pdf") 