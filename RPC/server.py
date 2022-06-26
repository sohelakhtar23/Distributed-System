from xmlrpc.server import SimpleXMLRPCServer
def factorial(n):
    if n<0:
        return "invalid!!"
    
    fact = 1
    for i in range (1,n+1):
        fact = fact *i
    return fact

server = SimpleXMLRPCServer(("localhost", 8000))
print("Listening on Port 8000")
server.register_function(factorial, "factorial")
server.serve_forever()
