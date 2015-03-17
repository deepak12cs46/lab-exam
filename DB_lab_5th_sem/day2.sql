#Q1 : find the names of all authors who has a post which is less than 10 characters long
select friendbook_author.name 
from friendbook_author,friendbook_post 
where friendbook_author.id = friendbook_post.author 
and length(friendbook_post.text)<10

#Q2 : find the names of authors who have more than 3 posts/comments
----!!!
select friendbook_author.name 
from friendbook_author,friendbook_post,friendbook_comment 
where friendbook_author.id=friendbook_post.author 
and friendbook_author.id=friendbook_comment.author
group by friendbook_author.id 
having count(friendbook_author.id)>=3 
union 
select friendbook_author.name 
from friendbook_author,friendbook_comment 
where friendbook_author.id=friendbook_comment.author 
group by friendbook_author.id 
having count(friendbook_author.id)>=3

#Q3 : list all authors as per their post/comment count1
---!!!
select friendbook_author.name,count(friendbook_post.author) as post_count 
from friendbook_author,friendbook_post 
where friendbook_author.id=friendbook_post.author 
group by (friendbook_post.author) 
having post_count>=3

union

select friendbook_author.name,count(friendbook_comment.author) as comment_count 
from friendbook_author,friendbook_comment 
where friendbook_author.id=friendbook_comment.author 
group by (friendbook_comment.author) 
having comment_count>=3

#Q4 : show all posts and comments and author name for author names starting with 'A'
select friendbook_post.text,friendbook_author.name
from friendbook_post,friendbook_author
where friendbook_post.author=friendbook_author.id
and friendbook_author.name like 'A%'
union
select friendbook_comment.text,friendbook_author.name
from friendbook_comment,friendbook_author
where friendbook_comment.author=friendbook_author.id
and friendbook_author.name like 'A%'

#Q5 : show city and country of authors who have posted posts having word 'hello'
select friendbook_author.city,friendbook_author.country
from friendbook_post,friendbook_author
where friendbook_author.id=friendbook_post.author
and friendbook_post.text like '%hello%'

#Q6 : show the comments posted by young fans with age<30 to the post of an author having name 'Messi'
select friendbook_comment.text 
from friendbook_comment,friendbook_author 
where friendbook_author.id=friendbook_comment.author
and friendbook_author.age<30 
and friendbook_comment.post in
(
    select friendbook_post.id 
    from friendbook_post,friendbook_author
    where friendbook_author.id=friendbook_post.author
    and friendbook_author.name='Messi'
)

#Q7 : find the comments of female fans associated with posts of authors residing in Barcelona, Spain
select friendbook_comment.text 
from friendbook_comment,friendbook_author 
where friendbook_author.id=friendbook_comment.author
and friendbook_author.gender='f' 
and friendbook_comment.post in
(
    select friendbook_post.id 
    from friendbook_post,friendbook_author
    where friendbook_author.id=friendbook_post.author
    and friendbook_author.city='Barcelona'
    and friendbook_author.country='Spain'
)

#Q8 : add column address to friendbook_author
alter table friendbook_author 
add column (address varchar(100))
