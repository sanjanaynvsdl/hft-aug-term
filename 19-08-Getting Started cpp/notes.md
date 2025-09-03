HFT?
- High frequency trading
- what does this do?
- Gold arbitrage -> Arbitrage two places having diff prizes, so we buy at a place where it is cheaper
- sell at a place where it's higher, 

### how does a real market work?
order book has buyers and sellers
1. buyers -> those who wanto buy at highest will be on top,
2. sellers -> those who want to sell at low prize will be on top, 
3. IN a market those who want to buy something will put a bid,
- the buyers are called bidders
- sellers are ask, 

### When the bids and asks, are equal a trade happens
- so this is done by matching engine, 
- why does this relate to hft are c++?
- we can buy at a market where the same stocks are lesser and sell at a another market where it's higher
- so thi sis what hft' firms does
- we need to be fast, latency matters becuase we can trade with just a single click
- there are alog's writtn to do this, 

- bids and asks whenever we have this, -> this is called market data
------------- now, 
1. we get the market data
2. parse, and validate data
3. sorting and the comparison
4. our algo's
5. then placing a order -> execution

- where do we get the market data from?
- we connect via a web scoket
- execution happens via a network
- what should i have when i want to connect via web socket?
- Internet, in a machine, any kind of network application use socket
- network requests happens through socket/port
- now this socket connects via web socket to an exchange

- do we need a socket for executio?
- exectution will be a network, this happens via socket right

-----------------------------------------------
- socket in java
- what type of socket class we have in java?
- write a dummy socket class
- read data from a java socket, 
- parse as string
- and do million of this operation
- we have socket in machine, nd we are reading million copies 
- we have a socket object, this does nothing but, 

- in the machine we have RAM and socket 
- nd we have a CPU,(process)
- now the procoess wants to read million entries from socket what it hsould do?
- it will need to connect to socket parse data to RAM, from RAm we read it in our process, 
- in socket obj we do obj.getData(); this returns some Bytes we parse or just print we do this a million time

- now when we run a spring application, - we see server is running on this PORt
- port is nothing but, it is making us to connecto outside world, 
- abstravtion of port is called socket

- like when we say int a= 10; this cratres a 4-bytes in the RAm, but we do get direct;y from RAM
- there is a layer of abstraction,n
- socket is nothing but a obj which is gviing api's through a port
- if we want to connect to a port we will do with a socket object, even for getData() we do on socket object
- socket : a object used to access port -> port connects us to the outside world
- every milli second market data changes,
