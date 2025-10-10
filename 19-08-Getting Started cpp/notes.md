# High Frequency Trading (HFT)

## What is HFT?
High Frequency Trading uses algorithms to execute trades at extremely high speeds to profit from small price differences.

### Arbitrage Example
- Buy assets at a lower price in one market
- Sell them at a higher price in another market
- Profit from the price difference

## How Markets Work

### Order Book
Markets have an order book with buyers and sellers:
1. **Buyers (Bidders)** - Those willing to pay the highest price are at the top
2. **Sellers (Asks)** - Those willing to sell at the lowest price are at the top
3. **Trade Execution** - When bid and ask prices match, a trade happens via the matching engine

### Why C++ for HFT?
- Speed is critical - latency matters when trades happen in milliseconds
- HFT firms buy stocks where prices are lower and sell where they're higher
- Algorithms are written to execute these trades automatically

## HFT Trading Pipeline

**Market Data** - Real-time bid and ask prices from exchanges

1. Get market data
2. Parse and validate data
3. Sort and compare
4. Run trading algorithms
5. Execute orders

## Network Communication

### Sockets
- Market data comes from exchanges via WebSocket connections
- Order execution also happens over the network
- Sockets are objects that provide APIs to access ports
- Ports connect applications to the outside world

### How It Works
1. Machine has RAM, CPU (process), and sockets
2. Process reads data from socket into RAM
3. Data is parsed and processed (done millions of times per second)
4. Socket object provides methods like `getData()` to retrieve bytes

### Abstraction Layer
- Just like `int a = 10` creates a 4-byte variable in RAM with abstraction
- Sockets provide an abstraction layer to access network ports
- Market data changes every millisecond, requiring fast processing
