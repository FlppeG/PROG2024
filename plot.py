import matplotlib.pyplot as plt
import numpy as np
import sys

#Read data
data = np.loadtxt(sys.argv[1])

#Plot data
fig, axes = plt.subplots(1, 1)
axes.plot(data[:, 1], data[:, 3])
axes.set_xscale("log")
axes.set_yscale("log")
axes.set_xlabel(r"$h$")
axes.set_ylabel(r"Error")

fig.savefig("fig_python.pdf")