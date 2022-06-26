import xmlrpc.client
with xmlrpc.client.ServerProxy("http://localhost:8000/") as proxy:
    while(1):
        n = int(input("Enter a number: "))
        print("Factorial of ", n, " = ", proxy.factorial(n))