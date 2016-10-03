import matplotlib.pyplot as plt
import numpy as np

n = np.arange(0, 50000, 1)
funcionComplejidad = n**4
plt.plot(n, funcionComplejidad)
plt.show()
