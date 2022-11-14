#1

trees
tree1<-trees["Girth"]>colMeans(trees["Girth"])
tree2<-trees["Height"]>80
tree3<-trees["Volume"]>50
sum(tree1&tree2&tree3)

#2

#(1)
install.packages("reshape2")
library(reshape2)

#(2)
tips

#(3)
head(tips)

#(4)
table(tips[,"day"])

#(5)
table(tips[,"time"])

#(6)
number<-table(tips[,"time"])
DinnerNum<-number[1]
LunchNum<-number[2]

Dinner<-subset(tips,time=="Dinner")
colSums(Dinner["total_bill"])/DinnerNum
colSums(Dinner["tip"])/DinnerNum
colSums(Dinner["size"])/DinnerNum

Lunch<-subset(tips,time=="Lunch")
colSums(Lunch["total_bill"])/LunchNum
colSums(Lunch["tip"])/LunchNum
colSums(Lunch["size"])/LunchNum

#(7)
percent<-tips[,"tip"]/tips[,"total_bill"]
mean(percent)
