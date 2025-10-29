import matplotlib.pyplot as plt
n_values = [4,8,16,32,64,128,256,512]
time_values=[0.000012,0.000053,0.000351,0.002609,0.015763,0.064138,0.391763,2.771975] # in seconds
plt.plot(n_values, time_values, marker='o')
plt.title("Strassen Matrix Multiplication: Time vs Matrix Size")
plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()