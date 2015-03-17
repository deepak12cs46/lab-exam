#author data entry
insert into friendbook_author(id,name,gender,city,country,age) values(1,'Abhisek','m','Kolkata','India',21);#1 row affected
insert into friendbook_author(id,name,gender,city,country,age) values(2,'Scarlett','f','Sydney','Australia',25);# 1 row affected. 
insert into friendbook_author(id,name,gender,city,country,age) values(3,'Obama','m','Washington','USA',47);# 1 row affected. 
insert into friendbook_author(id,name,gender,city,country,age) values(4,'Messi','m','Barcelona','Spain',26);# 1 row affected. 
insert into friendbook_author(id,name,gender,city,country,age) values(5,'Angelina','f','California','USA',38);# 1 row affected. 
insert into friendbook_author(id,name,gender,city,country,age) values(6,'Ibrahimovic','m','Stockholm','Sweden',26);# 1 row affected. 
insert into friendbook_author(id,name,gender,city,country,age) values(7,'Sharapova','f','Moscow','Russia',28);# 1 row affected.

#post data entry
insert into friendbook_post(id,text,type,author) 
values(1,'I wish we had won the worldcup... :( Germany was good, bad day for Argentina','status',4);

insert into friendbook_post(id,text,type,author) 
values (2,'whoaa!! this Friendbook is awesome','status',1);

insert into friendbook_post(id,text,type,author) 
values (3,'God bless America! *x50 :);) ','status',3);

insert into friendbook_post(id,text,type,author) 
values (4,'I love Sydney...the sand here is so good :)','status',2);

insert into friendbook_post(id,text,type,author) 
values (5,'<<photo of Messi and Neymar, in Barcelona>>','photo',4);

insert into friendbook_post(id,text,type,author) 
values (6,'<<video of Messi dribbling football>>','video',4);

insert into friendbook_post(id,text,type,author) 
values (7,'There is no comparison to the warmth and hospitaltity of Indians. Had a great time with the Indian PM today','status',3);

insert into friendbook_post(id,text,type,author) 
values (8,'Ouch! I do not know who is Tendulkar... :P','status',7);

insert into friendbook_post(id,text,type,author) 
values(9,'had a great time with the kids at the United Nations Child Care Home at Nairobi','status',3);

insert into friendbook_post(id,text,type,author) 
values (10,'Opened my football coaching center at Leeds :)','status',6);

insert into friendbook_post(id,text,type,author) 
values (11,'<<photo of Messi partying>>','photo',4);

insert into friendbook_post(id,text,type,author) 
values (12,'I guess modelling is good... ;)','status',7);

insert into friendbook_post(id,text,type,author) 
values (13,'hello.','status',1);

insert into friendbook_post(id,text,type,author) 
values (14,'<<pic>>','picture',7)


#comments data entry
insert into friendbook_comment(id,text,post,type,author) 
values(1,'i was supporting Argentina :( :(',1,'status',5);

insert into friendbook_comment(id,text,post,type,author) 
values(2,'Germany had excellent team work',1,'status',6);

insert into friendbook_comment(id,text,post,type,author) 
values(3,'yaay!! Germany won! Schweinsteiger rocks.',1,'status',7);

insert into friendbook_comment(id,text,post,type,author) 
values(4,'next time',1,'status',1);


