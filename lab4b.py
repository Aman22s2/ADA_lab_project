import matplotlib.pyplot as plt
sizes = [2, 4, 8, 16, 32, 64, 128, 256]
iterative = [0.000003, 0.000003, 0.000007, 0.000037, 0.000225, 0.001701, 0.012412,0.046565]
strassen = [0.000000, 0.000001, 0.000002, 0.000009, 0.000090, 0.000691, 0.005069,0.032787]
recursive = [0.000000, 0.000001, 0.000002, 0.000009, 0.000084, 0.000589, 0.004763,0.038664]
plt.figure(figsize=(8, 5))
plt.plot(sizes, iterative, marker='o', label='Iterative')
plt.plot(sizes, strassen, marker='s', label='Strassen')
plt.plot(sizes, recursive, marker='^', label='Recursive')
plt.xlabel('Matrix Size (n)')
plt.ylabel('Time (seconds)')
plt.title('Comparison of Matrix Multiplication Algorithms')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()