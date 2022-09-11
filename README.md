# RouteFinder
### Tired of asking, getting lost

With our app, you have the assistant along all the traffic journey with the complete network of subway lines you can find the way

we made an app that you give your starting point and dropping point and we give you the route

-Flexibility and extensibility in our designs applying ooad principles **Open-Closed principle**

-No duplication in our designs applying ooad principles **Don't repeat yourself principle**

-One Responsibility for each object in our designs applying ooad principles **Single Responsibility principle** 

    -our class station only holds what a station has and do station name and stations comparison
  
    -our class connection only hold what a connection have and do two stations that it connects
  
    -our class subway that has the stations and connections between them
  
    -subwayloader class that controls what stations we have
  
    -subwayprint class to be able to visualize output alone
  
We used case-driven development by dividing our cases into two use cases

    -case 1: load networks of subway lines
    
        -Represent Subway lines and stations along each line.
        
        -load multiple subway lines into the program.
        
    -case 2: get directions
    
        -Figure out the valid route between two stations.
        
        -Print directions for a particular route.
        
