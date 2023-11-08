package org.example;

public class Photo {

    private String urlPhoto;

    private Long id;

    /**
     * Photo constructor with id
     * @param id customer id
     * @param urlPhoto url of photo
     */
    public Photo(Long id, String urlPhoto) {
        this.id = id;
        this.urlPhoto = urlPhoto;
    }
    /**
     * Photo constructor without id
     * @param urlPhoto url of photo
     */
    public Photo( String urlPhoto) {
        this.urlPhoto = urlPhoto;
    }

    /**
     * urlPhoto setter
     * @param urlPhoto url of photo
     */
    public void setUrlPhoto(String urlPhoto) {
        this.urlPhoto = urlPhoto;
    }

    /**
     * urlPhoto getter
     */
    public String getUrlPhoto() {
        return urlPhoto;
    }
}
