#Q9 list down all the author with age between 30 and 40 along with their 4th post.List the author name,post text and post date.
SELECT a.name,p.text,p.dates       
FROM friendbook_author as a,friendbook_post as p    
WHERE p.id IN
(SELECT p1.id             
  FROM Friendbook_Author a1,Friendbook_Post p1           
  WHERE a1.id=a.id
  AND rownum=4) 
AND a.age BETWEEN 30 AND 40;

#Q10 A person named 'messi' has habit of commenting on her own post.Find all her post having more than 5 comments made by herself.List the post text and 5th comment text.
select friendbook_author.name, friendbook_post.text, friendbook_post.id, friendbook_comment.text 
from friendbook_post,friendbook_author,friendbook_comment
where friendbook_author.id= friendbook_post.author 
and 
(friendbook_author.name= 'Messi' 
  or friendbook_author.name= 'Messi')
and friendbook_author.id= friendbook_comment.author 
and friendbook_post.id= friendbook_comment.post 
and friendbook_comment.post in 
(select friendbook_comment.post 
  from friendbook_post,friendbook_comment 
  where friendbook_comment.post= friendbook_post.id 
  group by friendbook_comment.post
  having count (friendbook_comment.post)>5) 
order by friendbook_post.id;

#Q11 list authors with date of their first post last post first comment or last comment.
SELECT a.name,pf.dates,pl.dates,cf.dates,cl.dates 
FROM friendbook_author as a,friendbook_post as pf,friendbook_post as pl,friendbook_comment as cf,friendbook_comment as cl 
WHERE pf.id=(SELECT min(p1.id)
from friendbook_post as p1,friendbook_post as p2                
WHERE p1.author=a.id) 
AND
pl.id=(SELECT max(p1.id) 
  from friendbook_post as p1,friendbook_post as p2                
  WHERE
p1.author=a.id) 
AND cf.id=(SELECT min(c1.id) 
  from friendbook_comment as c1,Friendbook_comment as c2
WHERE c1.c1.author=a.id) 
AND cf.id=(SELECT max(c1.id) 
  from friendbook_comment as c1,friendbook_comment as c2                
WHERE c1.author=a.id);

#Q12 Find average age of male authors having average post length between 10 and 50.
SELECT avg(age) 
FROM friendbook_author 
WHERE id IN(SELECT distinct a.id FROM friendbook_author as a,friendbook_post as p 
WHERE a.id=p.author and LENGTH(p.text)>40);

#Q13 sort the authors from cities having name starting with 'k' according to their post count and then by comment count.list down the author name,author id,city,post count and comment count
SELECT at.name,at.id,at.city,postcount,commentcount 
FROM (SELECT a.name as name,a.id as id ,a.city
as city FROM friendbook_author as a       
WHERE a.city like 'k%') at,
(SELECT p.author as
pauthor,count(p.author) as postcount 
FROM friendbook_post p GROUP BY p.author) pc,(SELECT c.author
as cauthor,count(c.author) as commentcount  
FROM friendbook_comment c GROUP BY c.author) cc 
WHERE at.id=cc.cauthor AND at.id=pc.pauthor 
ORDER BY postcount DESC,commentcount DESC
