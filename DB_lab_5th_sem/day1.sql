#Q1. friendbook database
CREATE TABLE friendbook_post(
text varchar(80),
id int primary key,
type varchar(10) check (type in ('video','picture','status')),
author int references friendbook_author.id
);

CREATE TABLE friendbook_author(
id int primary key,
name varchar(20),
gender varchar(1) not null check (gender in ('m','f')),
city varchar(20) not null,
country varchar(20) not null,
age int not null check (age>=16 and age<=105)
);

CREATE TABLE friendbook_comment(
text varchar(80),
id int primary key,
post int references friendbook_post(id),
type varchar(10) check(type in('video','picture','status')),
author int references friendbook_author(id)
);
