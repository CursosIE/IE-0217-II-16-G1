import matplotlib.pyplot as plt
import numpy as np

n = np.arange(0, 12500, 1)
funcionTiempoEjecucion = 1296*n**4 + 1728*n**3 + 2160*n**2 + 1056*n + 447
plt.plot(n, funcionTiempoEjecucion)
plt.show()
