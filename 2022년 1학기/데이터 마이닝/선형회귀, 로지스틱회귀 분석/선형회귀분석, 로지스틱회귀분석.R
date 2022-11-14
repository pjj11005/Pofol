# 선형회귀 분석

#1. 데이터 수집 및 전처리
install.packages('UsingR')
install.packages('psych')
library(UsingR)
str(babies)

# 의미없는 변수 지우기
# remove id,pluralty,outcome,sex
my_babies <- babies[, -c(1,2,3,6)] 
str(my_babies)

# 의미없는 각변수들의 값들 제거
my_babies <- my_babies[my_babies$wt != 999,]
my_babies <- my_babies[my_babies$gestation != 999,]
my_babies <- my_babies[my_babies$parity != 99,]
my_babies <- my_babies[my_babies$race != 99,]
my_babies <- my_babies[my_babies$age != 99,]
my_babies <- my_babies[my_babies$ed != 9,]
my_babies <- my_babies[my_babies$ht != 99,]
my_babies <- my_babies[my_babies$wt1 != 999,]
my_babies <- my_babies[my_babies$drace != 99,]
my_babies <- my_babies[my_babies$dage != 99,]
my_babies <- my_babies[my_babies$ded != 9,]
my_babies <- my_babies[my_babies$dwt != 999,]
my_babies <- my_babies[my_babies$dht != 99,]
my_babies <- my_babies[my_babies$inc != 98,]
my_babies <- my_babies[my_babies$inc != 99,]
my_babies <- my_babies[my_babies$smoke != 9,]
my_babies <- my_babies[my_babies$time != 98,]
my_babies <- my_babies[my_babies$time != 99,]
my_babies <- my_babies[my_babies$number != 98,]
my_babies <- my_babies[my_babies$number != 99,]

# 범주형 변수 변환
parity<-as.numeric(cut(my_babies$parity,c(0,1,2,3,4,5,6,7,8,9,10,11)))
race<-as.numeric(cut(my_babies$race,c(0,5,6,7,8,11)))
ed<-as.numeric(cut(my_babies$ed,c(0,2,3,4,5,7)))
drace<-as.numeric(cut(my_babies$drace,c(0,5,6,7,8,11)))
ded<-as.numeric(cut(my_babies$ded,c(0,2,3,4,5,7)))
marital<-as.numeric(cut(my_babies$marital,c(0,1,2,3,4,5)))
inc<-as.numeric(cut(my_babies$inc,c(0,1,2,3,4,5,6,7,8,9,10)))
smoke<-as.numeric(cut(my_babies$smoke,c(0,1,2,3,4)))
time<-as.numeric(cut(my_babies$time,c(0,1,2,3,4,5,6,7,8,9,10)))
number<-as.numeric(cut(my_babies$number,c(0,1,2,3,4,5,6,7,8,9)))

#스케일링(정규화)
normal<-function(x){
  return((x-min(x))/(max(x)-min(x)))
}
my_babies$date<-normal(my_babies$date)
my_babies$gestation<-normal(my_babies$gestation)
my_babies$wt<-normal(my_babies$wt)
my_babies$age<-normal(my_babies$age)
my_babies$ht<-normal(my_babies$ht)
my_babies$wt1<-normal(my_babies$wt1)
my_babies$dage<-normal(my_babies$dage)
my_babies$dht<-normal(my_babies$dht)
my_babies$dwt<-normal(my_babies$dwt)
str(my_babies)

#2.탐색적 데이터 분석
install.packages('corrplot')
library(corrplot)
par(mfrow=c(1,1))
corrplot(cor(my_babies[,c(1:3,6,8:9,11,13:14)]))

m<-lm(wt~gestation,my_babies)
plot(my_babies$gestation,my_babies$wt)
abline(coef(m))

sample<-cbind(my_babies$gestation,my_babies$wt)

barplot(sample[200:250,],beside = T,ylim = c(0,1),names.arg = c('gestation','wt'),
        main = 'gestation과 wt값의 비교')

par(mfrow=c(1,2))
t_gestation<-t(my_babies$gestation)
pie(t_gestation[,200:210],main = 'gestation값의 분포')
t_wt<-t(my_babies$wt)
pie(t_wt[,200:210],main = 'wt값의 분포')

hist(my_babies$gestation,main = 'gestation의 값의 분포',xlab='gestation의 값')
hist(my_babies$wt,main = 'wt의 값의 분포',xlab='wt의 값?')

#3.학습모델 구축
#단순선형회귀 모형 구축
model<-lm(wt~gestation,my_babies)
summary(model)

#다중선형회귀 모형 구축
multi_model<-lm(wt~date+gestation+parity+race+age+ed+ht+wt1+drace+dage+ded+dht+dwt+marital+
                  inc+smoke+time+number,my_babies)
summary(multi_model)
#3.1) age,dht,time 제거
multi_model<-lm(wt~date+gestation+parity+race+ed+ht+wt1+drace+dage+ded+dwt+marital+
                  inc+smoke+number,my_babies)
summary(multi_model)
#3.2) wt1,dage 제거
multi_model<-lm(wt~date+gestation+parity+race+ed+ht+drace+ded+dwt+marital+
                  inc+smoke+number,my_babies)
summary(multi_model)
#3.3) inc,drace,marital 제거
multi_model<-lm(wt~date+gestation+parity+race+ed+ht+ded+dwt+
                  smoke+number,my_babies)
summary(multi_model)
#3.4) ed, ded 제거
multi_model<-lm(wt~date+gestation+parity+race+ht+dwt+
                  smoke+number,my_babies)
summary(multi_model)
#3.5) date제거
multi_model<-lm(wt~gestation+parity+race+ht+dwt+
                  smoke+number,my_babies)
summary(multi_model)

anova(model,multi_model)
par(mfrow=c(1,1))
plot(multi_model,which = 5)

#4. 결과 해석
install.packages('forecast')
library(forecast)
accuracy(model)
accuracy(multi_model)


# 로지스틱 회귀분석

#1. 이진분류 성능평가 함수 정의
perf_eval <- function(cm){
  # true positive rate
  TPR = Recall = cm[2,2]/sum(cm[2,])
  # precision
  Precision = cm[2,2]/sum(cm[,2])
  # true negative rate
  TNR = cm[1,1]/sum(cm[1,])
  # accuracy
  ACC = sum(diag(cm)) / sum(cm)
  # balance corrected accuracy (geometric mean)
  BCR = sqrt(TPR*TNR)
  # f1 measure
  F1 = 2 * Recall * Precision / (Recall + Precision)
  
  re <- data.frame(TPR = TPR,
                   Precision = Precision,
                   TNR = TNR,
                   ACC = ACC,
                   BCR = BCR,
                   F1 = F1)
  return(re)
}
#2. 데이터 로드
install.packages('dummies')
install.packages('survival')
library(dummies)
library(survival)
str(colon)

#3. 데이터 전처리
colon<-na.omit(colon)
colon <- dummy.data.frame(colon, names=c("rx"))
head(colon,10)
colon<-colon[,-c(1:3)]
str(colon)
table(colon$status)

#4. 데이터 학습/테스트 구분
set.seed(2020)
test_id <- sample(1:nrow(colon), round(nrow(colon)*0.96))
colon_train <- colon[-test_id, ]
colon_test <- colon[test_id, ]
print("Training: ", str(nrow(colon_train)))
print("Test: ", str(nrow(colon_test)))

#5. 로지스틱회귀 모형 구축
model <- glm(status~., colon_train, family = binomial())
summary(model)

#6. 로지스틱회귀 모형 예측 수행
pred_prob <- predict(model, colon_test, type="response")
pred_class <- rep(0, nrow(colon_test))
pred_class[pred_prob > 0.5] <- 1 
cm1 <- table(pred=pred_class, actual=colon_test$status)
perf_eval(cm1)

#7. 변수 선택법 적용
#7.1) forward selection
model_fwd <- step(glm(status ~ 1, colon_train, family = binomial()), direction = "forward", trace = 0,
                  scope = formula(model))
                  
pred_prob <- predict(model_fwd, colon_test, type="response")
pred_class <- rep(0, nrow(colon_test))
pred_class[pred_prob > 0.5] <- 1
cm2 <- table(pred=pred_class, actual=colon_test$status)
perf_eval(cm2)
#7.2) stepwise selection
model_step <- step(glm(status ~ ., colon_train,
                       family = binomial()), direction = "both", trace = 0,
                   scope = list(lower=status ~ 1, upper = formula(model)))

pred_prob <- predict(model_step, colon_test, type="response")
pred_class <- rep(0, nrow(colon_test))
pred_class[pred_prob > 0.5] <- 1
cm3 <- table(pred=pred_class, actual=colon_test$status)
perf_eval(cm3)

#8. 결과 해석
cm1
cm2
cm3
