import matplotlib.pyplot as plt
n_values = [100, 200, 300, 400, 500]
time_values=[0.005284, 0.029439 , 0.091780, 0.220726, 0.467083] # in seconds
plt.plot(n_values, time_values, marker='o')
plt.title("Iterative Matrix Multiplication: Time vs Matrix Size")
plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()