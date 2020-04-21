docker run -v %cd%:/test --name monitor_container --rm --detach -i -t mw/monitor bash
docker exec -w /test monitor_container make 
docker stop monitor_container
